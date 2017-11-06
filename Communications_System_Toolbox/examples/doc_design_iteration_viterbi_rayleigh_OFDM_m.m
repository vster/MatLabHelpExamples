function [ber, bits]=doc_design_iteration_viterbi_rayleigh_OFDM_m(EbNo, ...
    MaxNumErrs, MaxNumBits)
%#codegen
%
%   doc_design_iteration_viterbi_rayleigh_OFDM_m example in Getting Started
%   documentation. This example, described in the Getting Started chapter
%   of the Communications Toolbox documentation, is used with bertool to
%   conduct a bit error rate simulation: 

%   Copyright 1996-2013 The MathWorks, Inc.

% Create preambles
pre1=0.5*((-1).^(0:1:99)+1);
pre2=0.5*((-1).^(1:100)+1);
Preamble=complex([pre1 0.0 pre2].');

% Set simulation parameters
M=4;
k=log2(M);
codeRate=2;

% Set channel parameters
snr = EbNo - 10*log10(codeRate) + 10*log10(k);
bitsPerFrame=186;
Ts = (25/(3e6))*(186/576);
pathDelays=[0 0.4 0.9]*1e-6;
pathGains=[0 -5 -10];
maxDoppler=5;

% Establish persistent variables
persistent hBitError hConvEncoder hModulator hAWGN hDemodulator ...
    hViterbi hFadingChannel hOFDMmod hOFDMdemod

% Create the necessary System objects
if isempty(hBitError )
    hBitError = comm.ErrorRate;
    hConvEncoder=comm.ConvolutionalEncoder(...
        'TerminationMethod','Terminated');
    hModulator = comm.PSKModulator('ModulationOrder',4, ...
        'PhaseOffset',pi/4, ...
        'BitInput',true);
    hAWGN = comm.AWGNChannel('NoiseMethod','Variance',...
        'VarianceSource','Input port');
    hDemodulator = comm.PSKDemodulator('ModulationOrder',4, ...
        'PhaseOffset',pi/4, ...
        'BitOutput',true, ...
        'DecisionMethod','Hard decision');
    hViterbi = comm.ViterbiDecoder(...
        'InputFormat','Hard',...
        'TerminationMethod','Terminated');
    hFadingChannel = comm.MIMOChannel(...
        'SampleRate', 1/Ts,...
        'PathDelays',pathDelays,...
        'AveragePathGains', pathGains,...
        'MaximumDopplerShift', maxDoppler,...
        'FadingDistribution','Rayleigh',...
        'TransmitCorrelationMatrix',1,...
        'ReceiveCorrelationMatrix',1,...
        'NormalizeChannelOutputs',false);
    hOFDMmod = comm.OFDMModulator('FFTLength',256,...
        'CyclicPrefixLength',32,...
        'NumGuardBandCarriers',[27;27],...
        'InsertDCNull',true,...
        'NumSymbols',2);
    hOFDMdemod = comm.OFDMDemodulator(hOFDMmod);
end
%% In-loop processing
numErrs = 0;
numBits = 0;
results=zeros(3,1);
while ((numErrs < MaxNumErrs) && (numBits < MaxNumBits))
    % Generate random binary data
    dataIn = randi([0 1],bitsPerFrame,1);
    
    % Convolutionally encode data
    dataEnc = step(hConvEncoder, dataIn);
    
    % Apply QPSK modulation
    modSig = step(hModulator, dataEnc);
    
    % Add pilots to modulated data prior to OFDM modulation
    ofdmPilot = localOFDM_Packer(modSig); 
    
    % Apply OFDM modulation
    ofdmSym = step(hOFDMmod, [Preamble ofdmPilot]);
    
    % Pass transmitted data through Rayleigh channel
    rayFiltSig = step(hFadingChannel, ofdmSym);
    
    % Determine the noise variance from the desired SNR and signal variance
    sigDB      = 10*log10(var(rayFiltSig));   
    noiseVar  = real(10.^(0.1*(sigDB-snr)));
    
    % Add AWGN to the received signal
    ofdmRx   = step(hAWGN, rayFiltSig, noiseVar);
    
    % Apply OFDM demodulation
    rxSig = step(hOFDMdemod, ofdmRx);
    
    % Using the preamble, apply equalization
    equalizedSig    = localOFDM_Equalizer(rxSig, Preamble);
    
    % Remove pilot symbols from the data
    sigNoPilots = localOFDM_Unpacker(equalizedSig);
    
    % Apply QPSK demodulation
    dataDemod = step(hDemodulator, sigNoPilots);
    
    % Using a Viterbi decoder, remove errors from the demodulated data
    dataOut = step(hViterbi, dataDemod);
    
    % Compute the error statistics
    results = step(hBitError, dataIn, dataOut(1:bitsPerFrame)); % Update BER
    numErrs = results(2);
    numBits = results(3);
end
% Return BER
ber = results(1);
bits= results(3);
reset(hBitError);
end

%% Local functions
function y = localOFDM_Packer(u)
IndexU=[1:12,1+(13:36),2+(37:60),3+(61:84),4+(85:96),5+(97:108), ...
    6+(109:132),7+(133:156),8+(157:180),9+(181:192)]';
IndexP=1+[12,1+36,2+60,3+84,4+96,5+108,6+132,7+156,8+180]';
ValsP=complex(1,0)*[1;-1;1;-1;0;-1;-1;1;1];
LEN=numel(u)+numel(IndexP);
y = complex(zeros(LEN,1));
y(IndexU)=u;
y(IndexP)=ValsP;
end

function y = localOFDM_Equalizer(u,P)
Index1=[1:2:99,103:2:201];
training=u(Index1,1);
Pilots=P(Index1);
Ch=training./Pilots;
gain=conj(Ch)./(Ch.*conj(Ch));
G=localRepeatGains(gain);
Index2=[1:100,102:201];
data=u(Index2,2);
y=G.*data;
end

function G = localRepeatGains(gain)
G=complex(zeros(2*numel(gain),1));
G(1:2:200)=gain;
G(2:2:200)=gain;
end

function y = localOFDM_Unpacker(u)
y = u([1:12, 14:37, 39:62, 64:87, 89:112, 114:137, ...
    139:162, 164:187, 189:200]);
end
