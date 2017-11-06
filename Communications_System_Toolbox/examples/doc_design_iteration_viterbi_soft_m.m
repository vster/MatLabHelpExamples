function [ber, bits]=doc_design_iteration_viterbi_soft(EbNo,MaxNumErrs,MaxNumBits)
%#codegen (5,200,1e7) Theory 8
% Parameters
rng('default');
M=4;k=log2(M);
codeRate=2;
snr = EbNo - 10*log10(codeRate) + 10*log10(k);
noise_var = 10.^(-snr/10);
QuantizerBoundaries=(-7:7);
FRM=2040;
%% Initialization
% Components
persistent hModulator hAWGN hDeModulator hBitError
persistent hConvEncoder hViterbi hQuantizer
if isempty(hModulator)
    hModulator = comm.QPSKModulator('PhaseOffset',pi/4,'BitInput',true);
    hAWGN = comm.AWGNChannel(...
        'NoiseMethod','Variance',...
        'VarianceSource','Input port');
    hDeModulator =  comm.QPSKDemodulator('BitOutput',true,...
        'DecisionMethod','Log-likelihood ratio',...
        'PhaseOffset',pi/4,...
        'VarianceSource', 'Input port');
    hBitError = comm.ErrorRate;
    %
    hQuantizer=dsp.ScalarQuantizerEncoder(...
        'Partitioning',  'Unbounded',...
        'BoundaryPoints', QuantizerBoundaries,...
        'OutputIndexDataType','uint8');
    hConvEncoder=comm.ConvolutionalEncoder(...
        'TerminationMethod','Terminated');
    hViterbi=comm.ViterbiDecoder(...
        'InputFormat','Soft',...
        'SoftInputWordLength', 4,...
        'OutputDataType', 'double',...
        'TerminationMethod','Terminated');
end
%% In-loop processing
numErrs = 0;
numBits = 0;
results=zeros(3,1);
while ((numErrs < MaxNumErrs) && (numBits < MaxNumBits))
    data    = double(randn(FRM, 1)>0.5);       % Generate data
    u1      = step(hConvEncoder, data);        % Convolutional Encoder
    mod_sig = step(hModulator, u1);            % QPSK Modulator
    rx_sig  = step(hAWGN,mod_sig, noise_var);             % AWGN channel
    uB      = step(hDeModulator, rx_sig, noise_var);      % QPSK Demodulator
    uC      = step(hQuantizer, -double(uB));
    y       = step(hViterbi,uC);               % Viterbi Decoder
    results = step(hBitError, data, y(1:FRM)); % Update BER
    numErrs = results(2);
    numBits = results(3);
end
% Return BER
ber = results(1);
bits= results(3);
reset(hBitError);
end