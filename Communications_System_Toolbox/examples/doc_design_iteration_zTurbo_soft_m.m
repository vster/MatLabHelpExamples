function [ber, bits]=doc_design_iteration_zTurbo_soft(EbNo,MaxNumErrs,MaxNumBits)
%#codegen (0:0.2:1)(200,5e6)
%% Initialization
rng('default');
FRM=2048;
Trellis=poly2trellis(4, [13 15], 13);
Indices=randperm(FRM);
M=4;k=log2(M);
R= FRM/(3* FRM + 4*3);
snr = EbNo + 10*log10(k) + 10*log10(R);
noise_var = 10.^(-snr/10);
% Components
persistent hModulator hAWGN hDeModulator hBitError
persistent hTurboEncoder hTurboDecoder
if isempty(hModulator)
    hModulator = comm.QPSKModulator('PhaseOffset',0,'BitInput',true);
    hAWGN = comm.AWGNChannel(...
        'NoiseMethod','Variance',...
        'VarianceSource','Input port');
    hDeModulator =  comm.QPSKDemodulator('BitOutput',true,...
        'DecisionMethod','Log-likelihood ratio',...
        'PhaseOffset',0,...
        'VarianceSource', 'Input port');
    hBitError = comm.ErrorRate;
    %
    hTurboEncoder=comm.TurboEncoder(...
        'TrellisStructure',Trellis,...
        'InterleaverIndices',Indices);
    hTurboDecoder=comm.TurboDecoder(...
        'TrellisStructure',Trellis,...
        'InterleaverIndices',Indices,...
        'NumIterations',6);
end
%% In-loop processing
numErrs = 0;
numBits = 0;
results=zeros(3,1);
while ((numErrs < MaxNumErrs) && (numBits < MaxNumBits))
    data    = double(randn(FRM, 1)>0.5);       % Generate data
    u1      = step(hTurboEncoder, data);       % Turbo Encoder
    mod_sig = step(hModulator, u1);            % QPSK Modulator
    rx_sig  = step(hAWGN,mod_sig,noise_var);   % AWGN channel
    uB      = step(hDeModulator, rx_sig,noise_var);      % QPSK Demodulator
    y       = step(hTurboDecoder,-uB);    % Turbo Decoder
    results = step(hBitError, data, y(1:FRM)); % Update BER
    numErrs = results(2);
    numBits = results(3);
end
% Return BER
ber = results(1);
bits= results(3);
reset(hBitError);










