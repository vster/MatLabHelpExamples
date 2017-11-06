function errorData = doc_qpsk_sim_with_awgn(EbNoVec, idx, ...
    totErrors, totBits)
% Function to determine the number of bit errors and total transmitted bits
% in a QSPK simulation assuming an AWGN channel.

% Create QPSK modulator and demodulator System objects
hMod = comm.QPSKModulator('BitInput',true);
hDemod = comm.QPSKDemodulator('BitOutput',true);

bitsPerSymbol = 2;  % QPSK

% Create error rate System object and preallocate errorData array
hError = comm.ErrorRate;
errorData = zeros(length(EbNoVec),3);

% Determine Eb/No from EbNoVec and the index, idx
EbNo = EbNoVec(idx);

% Reset the error rate object prior to loop execution
reset(hError)

% Create the AWGN channel
hAWGN = comm.AWGNChannel('BitsPerSymbol',bitsPerSymbol,'EbNo',EbNo);

% Main loop
while (errorData(idx,2) < totErrors) && (errorData(idx,3) < totBits)
    % Generate random data
    dataIn = randi([0, 1], bitsPerSymbol, 1);
    % Apply QPSK modulation
    txSig = step(hMod, dataIn);
    % Pass the signal through the AWGN channel
    rxSig = step(hAWGN, txSig);
    % Demodulate the received signal
    dataOut = step(hDemod, rxSig);
    % Calculate the error statistics
    errorStats = step(hError, dataOut, dataIn);
    % Pass the error statistics to the output array
    errorData(idx,:) = errorStats;
end

