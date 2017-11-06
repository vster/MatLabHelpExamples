function [ber,bits]=doc_design_iteration_viterbi_rayleigh_OFDM_MIMO_m(...
    EbNo, MaxNumErrs, MaxNumBits)
%#codegen

%   doc_design_iteration_viterbi_rayleigh_OFDM_MIMO_m example in Getting
%   Started documentation. This example, described in the Getting Started
%   chapter of the Communications Toolbox documentation, is used with
%   bertool to conduct a bit error rate simulation:

%   Copyright 1996-2013 The MathWorks, Inc.


% Create preambles
pre1 = ((-1).^(0:1:99)+1);
pre2=((-1).^(1:100)+1);
PreambleE = complex([pre1 0.0 pre2].');
PreambleO = complex(((-1).^(1:201)+1).');

% Set simulation parameters
M = 4;
k = log2(M);
codeRate = 2;
snr = EbNo - 10*log10(codeRate) + 10*log10(k);
bitsPerFrame = 378;

% Set MIMO channel parameters
Ts = (25/(3e6))*(378/864);
pathDelays=[0 0.4 0.9]*1e-6;
pathGains=[0 -5 -10];
maxDoppler=5;

%  Construct the necessary System objects
persistent hBitError  hAWGN hOFDMmod hOFDMdemod hConvEncoder hModulator ...
    hMIMOencoder hMIMO hMIMOdecoder hDemodulator hViterbi
if isempty(hBitError )
    hBitError = comm.ErrorRate;
    hAWGN = comm.AWGNChannel('NoiseMethod','Variance',...
        'VarianceSource','Input port');
    hOFDMmod = comm.OFDMModulator('FFTLength',256,'InsertDCNull',1,...
        'NumGuardBandCarriers',[27;27],'CyclicPrefixLength',32,...
        'NumTransmitAntennas',2,'NumSymbols',3);
    hOFDMdemod = comm.OFDMDemodulator(hOFDMmod);
    hConvEncoder = comm.ConvolutionalEncoder(...
        'TerminationMethod','Terminated');
    hModulator = comm.PSKModulator('ModulationOrder',4, ...
        'PhaseOffset',pi/4, ...
        'BitInput',true);
    hMIMOencoder = comm.OSTBCEncoder('NumTransmitAntennas', 2);
    hMIMO = comm.MIMOChannel(...
        'SampleRate', 1/Ts,...
        'PathDelays',pathDelays,...
        'AveragePathGains', pathGains,...
        'MaximumDopplerShift', maxDoppler,...
        'FadingDistribution','Rayleigh',...
        'ReceiveCorrelationMatrix',cat(3,1,1,1),...
        'RandomStream', 'mt19937ar with seed',...
        'Seed', 100,...
        'NormalizeChannelOutputs',false);
    hMIMOdecoder = comm.OSTBCCombiner('NumTransmitAntennas', 2,...
        'NumReceiveAntennas',1);
    hDemodulator = comm.PSKDemodulator('ModulationOrder',4, ...
        'PhaseOffset',pi/4, ...
        'BitOutput',true, ...
        'DecisionMethod','Hard decision');
    hViterbi = comm.ViterbiDecoder(...
        'InputFormat','Hard',...
        'TerminationMethod','Terminated');

end
%% In-loop processing
numErrs = 0;
numBits = 0;
results=zeros(3,1);
while ((numErrs < MaxNumErrs) && (numBits < MaxNumBits))
    % Generate random binary data
    dataIn = randi([0 1],bitsPerFrame,1);
    
    % Convolutionally encode data and apply QPSK modulation
    dataEncoded = step(hConvEncoder, dataIn);
    dataMod = step(hModulator, dataEncoded);
    
    % Add pilots for channel estimation
    dataModPilots = localOFDM_Packer(dataMod);
    
    % Apply 2x1 STBC MIMO Encoding
    txStreams = step(hMIMOencoder, dataModPilots);
    ofdmInput = cat(3, [PreambleE txStreams(:,:,1)], ...
        [PreambleO txStreams(:,:,2)]);
    
    % Apply OFDM modulation
    ofdmModData = step(hOFDMmod, ofdmInput);
    
    % Pass the transmitted signal through a 2x1 MIMO channel
    fadedSignal = step(hMIMO, ofdmModData);
    
    % Calculate the noise variance from the desired snr and signal variance
    sigDB = 10*log10(var(fadedSignal));         % Compute Signal Variance
    noiseVar = real(10.^(0.1*(sigDB-snr)));    % Compute Noise Variance
    
    % Add AWGN to the received signal
    receiveSignal = step(hAWGN, fadedSignal, noiseVar);
    
    % Apply OFDM demodulation
    ofdmOutput = step(hOFDMdemod, receiveSignal);
    
    % Using the preamble, apply channel equalization
    [eqSig, pathGains] = localOFDM_Equalizer(ofdmOutput, ...
        PreambleE, PreambleO);
    
    % Apply STBC decoding
    combinedSig = step(hMIMOdecoder, eqSig, pathGains);
    
    % Separate OFDM pilots from the data
    sigNoPilots = localOFDM_UnPacker(combinedSig);
    
    % QPSK demodulate and Viterbi decode the received data
    dataDemod = step(hDemodulator, sigNoPilots);    % QPSK Demodulator
    dataOut = step(hViterbi, dataDemod);      % Viterbi Decoder
    
    dataOut =  dataOut(1:numel(dataIn));
    
    % Calculate the error statistics
    results = step(hBitError, dataIn, dataOut); % Update BER
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
tmp = reshape(u, 192, 2);
IndexU = [1:12, 1+(13:36), 2+(37:60), 3+(61:84), 4+(85:96), ...
    5+(97:108), 6+(109:132), 7+(133:156), 8+(157:180), 9+(181:192)]';
IndexP = 1+[12, 1+36, 2+60, 3+84, 4+96, 5+108, 6+132, 7+156, 8+180]';
ValsP = complex([1;1]*[1,-1,1,-1,0,-1,-1,1,1]).';
len = size(tmp,1)+size(ValsP,1);
y = complex(zeros(len,2));
y(IndexU,:) = tmp;
y(IndexP,:)=ValsP;
end

function [y, pathGains] = localOFDM_Equalizer(u,P0,P1)
Index0 = [1:2:99,103:2:201];
Index1 = (2:2:201);
IndexU = [1:100,102:201];
Pilots0 = P0(Index0,1);
Pilots1 = P1(Index1,1);
training0 = u(Index0,1);
training1 = u(Index1,1);
y = u(IndexU,2:3);
y0 = localRepeatGains(training0,Pilots0);
y1 = localRepeatGains(training1,Pilots1);
pathGains = cat(3, y0, y1);
end

function G = localRepeatGains(training,Pilots)
[Row,Col]=size(training);
Ch=training./Pilots;
gain=[Ch,Ch];
G=complex(zeros(2*Row,2*Col));
G(1:2:2*Row,:)=gain;
G(2:2:2*Row,:)=gain;
end

function y = localOFDM_UnPacker(u)
IndexU = [1:12 14:37 39:62 64:87 89:112 114:137 139:162 164:187 189:200]';
tmp = u(IndexU,:);
y = tmp(:);
end