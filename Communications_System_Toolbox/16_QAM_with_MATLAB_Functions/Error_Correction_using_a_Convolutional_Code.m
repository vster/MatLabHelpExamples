%% Establish Simulation Framework

% Set the simulation variables. The number of bits is 
% increased from the previous example so that the bit error 
% rate may be estimated more accurately.

M = 16;                                         % Size of signal constellation
k = log2(M);                                    % Number of bits per symbol
numBits = 100000;                               % Number of bits to process
numSamplesPerSymbol = 4;                        % Oversampling factor

%% Generate Random Data

rng('default')                                  % Use default random number generator
dataIn = randi([0 1], numBits, 1);              % Generate vector of binary data

%% Convolutional Encoding

% Define a convolutional coding trellis for a rate 2/3 code.

tPoly = poly2trellis([5 4],[23 35 0; 0 5 13]);
codeRate = 2/3;

% Encode the input data using the previously created trellis.

dataEnc = convenc(dataIn, tPoly);

%% Modulate Data
% The encoded binary data is converted into an integer format so that 16-QAM 
% modulation can be applied.

% Reshape the input vector into a matrix of 4-bit binary data, which 
% is then converted into integer symbols.

dataEncMatrix = reshape(dataEnc, ...
    length(dataEnc)/k, k);                      % Reshape data into binary 4-tuples
dataSymbolsIn = bi2de(dataEncMatrix);           % Convert to integers

% Apply 16-QAM modulation.

dataMod = qammod(dataSymbolsIn, M);

%% Raised Cosine Filtering

% Specify the filter span and rolloff factor for the square-root, raised cosine filter.

span = 10;        % Filter span in symbols
rolloff = 0.25;   % Roloff factor of filter

% Create the filter using the rcosdesign function.

rrcFilter = rcosdesign(rolloff, span, numSamplesPerSymbol);

% Using the upfirdn function, upsample and apply the square-root, raised cosine filter.

txSignal = upfirdn(dataMod, rrcFilter, numSamplesPerSymbol, 1);

%% AWGN Channel

% Calculate the signal-to-noise ratio, SNR, based on the input Eb/N0, 
% the number of samples per symbol, and the code rate.

EbNo = 10;
snr = EbNo + 10*log10(k*codeRate)-10*log10(numSamplesPerSymbol);

% Pass the filtered signal through an AWGN channel.

rxSignal = awgn(txSignal, snr, 'measured');

%% Receive and Demodulate Signal
% Filter the received signal using the RRC filter and remove a portion of 
% the signal to account for the filter delay in order to make a meaningful BER comparison.

rxFiltSignal = upfirdn(rxSignal,rrcFilter,1,numSamplesPerSymbol);   % Downsample and filter
rxFiltSignal = rxFiltSignal(span+1:end-span);                       % Account for delay

% Demodulate the received, filtered signal using the qamdemod function.

dataSymbolsOut = qamdemod(rxFiltSignal, M);

%% Viterbi Decoding
% Use the de2bi function to convert the incoming integer symbols into bits.

dataOutMatrix = de2bi(dataSymbolsOut,k);
codedDataOut = dataOutMatrix(:);                 % Return data in column vector

traceBack = 16;                                             % Traceback length for decoding
numCodeWords = floor(length(codedDataOut)*2/3);             % Number of complete codewords
dataOut = vitdec(codedDataOut(1:numCodeWords*3/2), ...      % Decode data
           tPoly,traceBack,'cont','hard');
       
%% BER Calculation

% Using the biterr function, compare dataIn and dataOut to obtain the number 
% of errors and the bit error rate while taking the decoding delay into account

decDelay = 2*traceBack;                                     % Decoder delay, in bits
[numErrors, ber] = ...
   biterr(dataIn(1:end-decDelay),dataOut(decDelay+1:end));

fprintf('\nThe bit error rate = %5.2e, based on %d errors\n', ...
    ber, numErrors)

