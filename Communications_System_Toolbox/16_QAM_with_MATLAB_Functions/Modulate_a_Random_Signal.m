%% Generate a Random Binary Data Stream

% Define parameters.

M = 16;                     % Size of signal constellation
k = log2(M);                % Number of bits per symbol
n = 30000;                  % Number of bits to process
numSamplesPerSymbol = 1;    % Oversampling factor

% Create a binary data stream as a column vector.

rng('default')              % Use default random number generator
dataIn = randi([0 1],n,1);  % Generate vector of binary data

% Plot the first 40 bits in a stem plot.

stem(dataIn(1:40),'filled');
title('Random Bits');
xlabel('Bit Index'); ylabel('Binary Value');

%% Convert the Binary Signal to an Integer-Valued Signal
% Perform a bit-to-symbol mapping.

dataInMatrix = reshape(dataIn, length(dataIn)/4, 4); % Reshape data into binary 4-tuples
dataSymbolsIn = bi2de(dataInMatrix);                 % Convert to integers

% Plot the first 10 symbols in a stem plot.

figure; % Create new figure window.
stem(dataSymbolsIn(1:10));
title('Random Symbols');
xlabel('Symbol Index'); ylabel('Integer Value');

%% Modulate using 16-QAM

dataMod = qammod(dataSymbolsIn, M);

%% Add White Gaussian Noise
%Calculate the SNR when the channel has an Eb/N0 = 10 dB.

EbNo = 10;
snr = EbNo + 10*log10(k) - 10*log10(numSamplesPerSymbol);

% Pass the signal through the AWGN channel.

receivedSignal = awgn(dataMod, snr, 'measured');

%% Create a Constellation Diagram
% Use the scatterplot function to show the constellation diagram.

sPlotFig = scatterplot(receivedSignal, 1, 0, 'g.');
hold on
scatterplot(dataMod, 1, 0, 'k*', sPlotFig)

%% Demodulate 16-QAM
% Demodulate the received signal using the qamdemod function.

dataSymbolsOut = qamdemod(receivedSignal, M);

%% Convert the Integer-Valued Signal to a Binary Signal
% Reverse the bit-to-symbol mapping performed earlier.

dataOutMatrix = de2bi(dataSymbolsOut,k);
dataOut = dataOutMatrix(:);                 % Return data in column vector

%% Compute the System BER
% Use the error rate function to compute the error statistics and use fprintf to display the results.

[numErrors, ber] = biterr(dataIn, dataOut);
fprintf('\nThe bit error rate = %5.2e, based on %d errors\n', ...
    ber, numErrors)
