%% Pulse Shaping Using a Raised Cosine Filter
% This example, described in the Getting Started chapter of the
% Communications Toolbox documentation, aims to solve the following
% problem:
%
% Modify the Gray-coded modulation example (COMMDOC_GRAY)
% so that it uses a pair of square root raised cosine filters
% to perform pulse shaping and matched filtering at the
% transmitter and receiver, respectively.

% Copyright 1996-2013 The MathWorks, Inc.

%% Setup
% Define parameters
M = 16;                     % Size of signal constellation
k = log2(M);                % Number of bits per symbol
n = 3e4;                    % Number of bits to process
nSamp = 4;                  % Oversampling factor

%% Create Modulator and Demodulator
hMod = modem.qammod(M);         % Create a 16-QAM modulator
hMod.InputType = 'Bit';         % Accept bits as inputs
hMod.SymbolOrder = 'Gray';      % Accept bits as inputs
hDemod = modem.qamdemod(hMod);  % Create a 16-QAM based on the modulator

%% Filter Definition
% Filter-related parameters
Span = 10;        % Filter span in symbols
rolloff = 0.25;   % Roloff factor of filter

% Create a square-root raised cosine filter
rrcFilter=rcosdesign(rolloff,Span,nSamp);

% Plot impulse response
impz(rrcFilter);

%% Signal Source
% Create a binary data stream as a column vector
x = randi([0 1],n,1); % Random binary data stream

%% Modulation
% Modulate using 16-QAM
y = modulate(hMod,x);

%% Transmitted Signal
% Upsample and apply square-root raised cosine filter
yTx = upfirdn(y,rrcFilter,nSamp,1);
yTx = yTx(1:n);

% Create eye diagram for part of the filtered signal
eyediagram(yTx(1:2000),nSamp*2);

%% Channel
% Send signal over an AWGN channel
EbNo = 10; % In dB
SNR = EbNo + 10*log10(k) - 10*log10(nSamp);
yNoisy = awgn(yTx,SNR,'measured');

%% Received Signal
% Filter received signal using a square-root raised cosine filter
yRx = upfirdn(yNoisy,rrcFilter,1,nSamp);  % Downsample and filter
yRx = yRx(Span+1:end-2*Span);               % Account for delay

%% Scatter Plot
% Create scatter plot of received signal before and
% after filtering
h = scatterplot(sqrt(nSamp)*yNoisy(1:nSamp*5e3),nSamp,0,'g.');
hold on;
scatterplot(yRx(1:5e3),1,0,'kx',h);
title('Received Signal, Before and After Filtering');
legend('Before Filtering','After Filtering');
axis([-5 5 -5 5]); % Set axis ranges
hold off;

%% Demodulation
% Demodulate signal using 16-QAM
z = demodulate(hDemod,yRx);

%% BER Computation
% Compare x and z to obtain the number of errors and
% the bit error rate
[number_of_errors,bit_error_rate] = biterr(x(1:end-2*Span*k),z)
