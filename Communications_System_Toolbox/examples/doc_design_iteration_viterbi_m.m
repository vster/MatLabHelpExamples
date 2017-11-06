function [ber, bits]=doc_design_iteration_viterbi(EbNo,MaxNumErrs,MaxNumBits)
%#codegen (7,200,1e7) Theory 8
%% Initialization
% Components
persistent hModulator hAWGN hDeModulator hBitError
persistent hConvEncoder hViterbi
if isempty(hModulator)
    hModulator = comm.PSKModulator(...
        'ModulationOrder',4, ...
        'PhaseOffset',0, ...
        'BitInput',true);
    hAWGN = comm.AWGNChannel;
    hDeModulator = comm.PSKDemodulator(...
        'ModulationOrder',4, ...
        'PhaseOffset',0, ...
        'BitOutput',true, ...
        'DecisionMethod','Hard decision');
    hBitError = comm.ErrorRate;
    %
    hConvEncoder=comm.ConvolutionalEncoder(...
        'TerminationMethod','Terminated');
    hViterbi=comm.ViterbiDecoder(...
        'InputFormat','Hard',...
        'OutputDataType', 'double',...
        'TerminationMethod','Terminated');
end
% Parameters
FRM=2040;
M=hModulator.ModulationOrder;k=log2(M);
codeRate=2;
snr = EbNo - 10*log10(codeRate) + 10*log10(k);
hAWGN.EbNo=snr;
%% In-loop processing
numErrs = 0;
numBits = 0;
results=zeros(3,1);
while ((numErrs < MaxNumErrs) && (numBits < MaxNumBits))
    data    = double(randn(FRM, 1)>0.5);       % Generate data
    u1      = step(hConvEncoder, data);        % Convolutional Encoder
    mod_sig = step(hModulator, u1);            % QPSK Modulator
    rx_sig  = step(hAWGN,mod_sig);             % AWGN channel
    uB      = step(hDeModulator, rx_sig);      % QPSK Demodulator
    y       = step(hViterbi,uB);               % Viterbi Decoder
    results = step(hBitError, data, y(1:FRM)); % Update BER
    numErrs = results(2);
    numBits = results(3);
end
% Return BER
ber = results(1);
bits= results(3);
reset(hBitError);










