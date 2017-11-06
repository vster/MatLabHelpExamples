function [SER SERACI] = commdoc_passband_mod(nTx, EbNoVect)
%%  Passband Modulation with Adjacent Channel Interference
% [SER SERACI] = commdoc_passband_mod(nTx, EbNoVect) simulates a passband
% communications system using 16-QAM baseband modulation objects and frequency
% up and downconverters, and using an additive white Gaussian noise channel with
% interference in the passband caused by a tone in an adjacent channel that has
% been processed by a cubic nonlinearity. Simulations are performed for a number
% of frame transmissions specified by nTx, and for baseband Eb/No values
% specified in the EbNoVect input. The function returns symbol error rate
% results, SER, for the passband simulation without adjacent channel
% interference, and symbol error rate results SERACI, for the passband
% simulation with adjacent channel interference.

% Copyright 2009 The MathWorks, Inc.

%% Initialization

Fc = 2.5e6;                % Carrier frequency (Hz)
Rsym = 1e6;                % Symbol rate (symbols/second)
nSamps = 8;                % Number of samples per symbol
Fs = Rsym * nSamps;        % Sampling frequency (Hz)
frameLength = 5000;        % Number of symbols in a frame
M = 16;                    % Modulation order (16-QAM)
Fint = Fc/3+50e3;          % Tonal interference frequency
Aint = 0.45;               % Tonal interference amplitude

%% Setup

% Create a 16-QAM modulator and demodulator.
hMod = modem.qammod('M',M);
hDemod = modem.qamdemod(hMod);

% Pulse shaping: specify a square root raised cosine filter with a filter length
% of eight symbols and a rolloff factor of 0.2.
nSym = 8;   % Length of the filter in symbols
beta = 0.2; % Rolloff factor
filterSpec = fdesign.pulseshaping(nSamps, 'Square root raised cosine', ...
    'Nsym,Beta', nSym, beta);
hXmtFlt = design(filterSpec);
hXmtFlt.PersistentMemory = true;
hRcvFlt = copy(hXmtFlt);
hRcvFltACI = copy(hXmtFlt);

% Create a scatter plot scope to display constellation of received signal with
% no adjacent channel interference.
scatScope = commscope.ScatterPlot('SamplingFrequency', Rsym, ...
    'SamplesPerSymbol', 1, ...
    'Constellation', hMod.Constellation);
scatScope.PlotSettings.Constellation = 'on';
scatScope.PlotSettings.ConstellationStyle = '*r';

% Compute signal power.
avgPwrBaseBand16QAM = 10*log10(sum(abs(hMod.Constellation).^2)/(M*nSamps));
sigPower = 10*log10(sum(hXmtFlt.Numerator.^2)) + avgPwrBaseBand16QAM;

%% Simulation

% Initialize error counters and loop over the desired number of transmissions
% and for all EbNo values.
numErr = zeros(length(EbNoVect),1);
numErrACI = zeros(length(EbNoVect),1);
for idx = 1:length(EbNoVect)    
    tStart = 0;
    SNR = EbNoVect(idx) + 10*log10(log2(M)/nSamps) + 10*log10(2);
    
    for p = 1:nTx 
        b = randi([0 hMod.M-1], frameLength, 1);
        txSym = modulate(hMod, b);    
    
        % Pulse shaping.
        x = filter(hXmtFlt, upsample(txSym, nSamps));

        % Upconvert to passband.
        tEnd = (tStart+frameLength/Rsym)-1/Fs;
        t = (tStart:1/Fs:tEnd).';
        tStart = tEnd;
        carrier = sqrt(2)*exp(1i*2*pi*Fc*t);                        
        xUp = real(x.*carrier);
        
        % Add AWGN.          
        yUp = awgn(xUp, SNR, sigPower);
        
        % Add adjacent channel interference.
        interference = Aint*cos(2*pi*Fint*t+pi/8).^3;
        yUpACI = yUp + interference;
        
        % Downconvert signals with and without adjacent channel interference
        % (Assumes perfect synchronization).
        y = yUp.*conj(carrier);
        yACI = yUpACI.*conj(carrier);
    
        % Apply matched filter.
        rcvSym = filter(hRcvFlt, y);
        rcvSymACI = filter(hRcvFltACI, yACI);
        
        % Amplify the received signal symbols to place them around the center of
        % the 16-QAM constellation points.       
        rcvSym = nSym*rcvSym;
        rcvSymACI = nSym*rcvSymACI;
        
        % Downsample the signals.
        e2eDelay = nSamps*nSym;
        rcvSymDown = rcvSym(e2eDelay+1:nSamps:end);
        rcvSymDownACI = rcvSymACI(e2eDelay+1:nSamps:end);
        
        % Update the scatter plot for the signal without adjacent channel
        % interference.
        update(scatScope, rcvSymDown)
        if p == 1
            autoscale(scatScope)
        end
    
        % Demodulate.
        xHat = demodulate(hDemod, rcvSymDown);    
        xHatACI = demodulate(hDemod, rcvSymDownACI);    
    
        % Compute number of symbol errors.
        numErr(idx) = numErr(idx) + sum(xHat~=b(1:end-nSym));    
        numErrACI(idx) = numErrACI(idx) + sum(xHatACI~=b(1:end-nSym));    
    end
    
    % Reset the filters before starting simulations for a new SNR value.
    reset(hXmtFlt);
    reset(hRcvFlt);
    reset(hRcvFltACI);
end

% Compute symbol error rate with and without a tonal interference processed by a
% nonlinearity.
SER = numErr/(frameLength*nTx);
SERACI = numErrACI/(frameLength*nTx);
