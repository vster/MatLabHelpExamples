%% Establish Simulation Framework
% Set the simulation parameters.

M = 16;                     % Size of signal constellation
k = log2(M);                % Number of bits per symbol
numBits = 3e5;              % Number of bits to process
numSamplesPerSymbol = 4;    % Oversampling factor

%% Create Raised Cosine Filter
% Set the square-root, raised cosine filter parameters.

span = 10;        % Filter span in symbols
rolloff = 0.25;   % Roloff factor of filter

% Create a square-root, raised cosine filter using the rcosdesign function.

rrcFilter = rcosdesign(rolloff, span, numSamplesPerSymbol);

% Display the RRC filter impulse response using the fvtool function.

fvtool(rrcFilter,'Analysis','Impulse')

%% BER Simulation
% Use the randi function to generate random binary data. 
% The rng function should be set to its default state 
% so that the example produces repeatable results.

rng('default')                      % Use default random number generator
dataIn = randi([0 1], numBits, 1);  % Generate vector of binary data

% Reshape the input vector into a matrix of 4-bit binary data, 
% which is then converted into integer symbols.

dataInMatrix = reshape(dataIn, length(dataIn)/k, k); % Reshape data into binary 4-tuples
dataSymbolsIn = bi2de(dataInMatrix);

% Apply 16-QAM modulation using qammod.

dataMod = qammod(dataSymbolsIn, M);

% Using the upfirdn function, upsample and apply the square-root, raised cosine filter.

txSignal = upfirdn(dataMod, rrcFilter, numSamplesPerSymbol, 1);

% Set the Eb/N0 to 10 dB and convert the SNR given the number of bits per 
% symbol, k, and the number of samples per symbol.

EbNo = 10;
snr = EbNo + 10*log10(k) - 10*log10(numSamplesPerSymbol);

% Pass the filtered signal through an AWGN channel.

rxSignal = awgn(txSignal, snr, 'measured');

% Filter the received signal using the square-root, raised cosine filter 
% and remove a portion of the signal to account for the filter delay in order to make a meaningful BER comparison.

rxFiltSignal = upfirdn(rxSignal,rrcFilter,1,numSamplesPerSymbol);   % Downsample and filter
rxFiltSignal = rxFiltSignal(span+1:end-span);                       % Account for delay

% Apply 16-QAM demodulation to the received, filtered signal.

dataSymbolsOut = qamdemod(rxFiltSignal, M);

% Using the de2bi function, convert the incoming integer symbols into binary data.

dataOutMatrix = de2bi(dataSymbolsOut,k);
dataOut = dataOutMatrix(:);                 % Return data in column vector

% Apply the biterr function to determine the number of errors and the associated BER.

[numErrors, ber] = biterr(dataIn, dataOut);
fprintf('\nThe bit error rate = %5.2e, based on %d errors\n', ...
    ber, numErrors)

%% Visualization of Filter Effects
% Create an eye diagram for a portion of the filtered signal.

eyediagram(txSignal(1:2000),numSamplesPerSymbol*2);

% Created a scatter plot of the received signal before and after filtering.

h = scatterplot(sqrt(numSamplesPerSymbol)*...
    rxSignal(1:numSamplesPerSymbol*5e3),...
    numSamplesPerSymbol,0,'g.');
hold on;
scatterplot(rxFiltSignal(1:5e3),1,0,'kx',h);
title('Received Signal, Before and After Filtering');
legend('Before Filtering','After Filtering');
axis([-5 5 -5 5]); % Set axis ranges
hold off;