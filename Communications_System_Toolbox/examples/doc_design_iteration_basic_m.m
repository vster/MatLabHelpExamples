function [ber, bits]=doc_design_iteration_basic_m(EbNo,MaxNumErrs,MaxNumBits)
%#codegen (18,200,1e7)
%% Initialization
% Components
persistent hModulator hAWGN hDeModulator hBitError
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
end
% Parameters
FRM=2040;
M=hModulator.ModulationOrder;k=log2(M);
codeRate=1;
snr = EbNo + 10*log10(codeRate) + 10*log10(k);
hAWGN.EbNo=snr;
%% In-loop processing
numErrs = 0;
numBits = 0;
results=zeros(3,1);
while ((numErrs < MaxNumErrs) && (numBits < MaxNumBits))
    data    = randi([0, 1], FRM, 1);           % Generate data
    mod_sig = step(hModulator,   data);        % QPSK Modulator
    rx_sig  = step(hAWGN,        mod_sig);     % AWGN channel
    y =       step(hDeModulator, rx_sig);      % QPSK Demodulator
    results = step(hBitError,    data, y);     % Update BER
    numErrs = results(2);
    numBits = results(3);
end
% Return BER
ber = results(1);
bits= results(3);
reset(hBitError);










