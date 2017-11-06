function  [ber, bits]=doc_design_iteration_viterbi_rayleigh(EbNo,MaxNumErrs,MaxNumBits)
%%%
% Constants
M=4;k=log2(M);codeRate=2;
snr = EbNo - 10*log10(codeRate) + 10*log10(k);
bitsPerFrame=186;
Ts = (25/(3e6))*(186/576);
pathDelays=[0 0.4 0.9]*1e-6;
pathGains=[0 -5 -10];
maxDoppler=5;
persistent hConvEncoder hModulator hAWGN hDeModulator  hViterbi  hBitError  chanObj
 
if isempty(hConvEncoder)
%  System objects
hConvEncoder=comm.ConvolutionalEncoder(...
        'TerminationMethod','Terminated');
    hModulator = comm.PSKModulator('ModulationOrder',4, ...
        'PhaseOffset',pi/4, ...
        'BitInput',true);
    hAWGN=comm.AWGNChannel('NoiseMethod','Variance',...
        'VarianceSource','Input port');
    hBitError = comm.ErrorRate;
    hDeModulator = comm.PSKDemodulator('ModulationOrder',4, ...
        'PhaseOffset',pi/4, ...
        'BitOutput',true, ...
        'DecisionMethod','Hard decision');
    hViterbi=comm.ViterbiDecoder(...
        'InputFormat','Hard',...
        'OutputDataType', 'logical',...
        'TerminationMethod','Terminated');
     %  Objects

    % Create a Rayleigh channel object
        chanObj = rayleighchan(Ts, maxDoppler, pathDelays,pathGains) ;
        chanObj.StoreHistory = 1;
        chanObj.ResetBeforeFiltering = 0;
end
%% In-loop processing
numErrs = 0;
numBits = 0;
results=zeros(3,1);
while ((numErrs < MaxNumErrs) && (numBits < MaxNumBits))
    data = randn(bitsPerFrame, 1)>0.5;
    u1 = step(hConvEncoder, data);                                                    % Convolutional Encoder
    mod_sig = step(hModulator, u1);                                                  % QPSK Modulator
    rayFiltSig = filter(chanObj, mod_sig);                                        % Rayleigh Channel Model
    sigDB      = 10*log10(var(rayFiltSig));                                            % Compute Signal Variance
    noise_var  = real(10.^(0.1*(sigDB-snr)));                                    % Compute Noise Variance
    rec_sig   = step(hAWGN, rayFiltSig, noise_var);                         % AWGN channel
                       
    % Plot the new data from this iteration
    uB = step(hDeModulator, rec_sig);                                               % QPSK Demodulator
    y = step(hViterbi,int8(uB));                                                              % Viterbi Decoder
    results = step(hBitError, data, y(1:bitsPerFrame)); % Update BER
    numErrs = results(2);
    numBits = results(3);
end
% Return BER
ber = results(1);
bits= results(3);
reset(hBitError);
