%% Using a Convolutional Code
% This example, described in the Getting Started chapter of the
% Communications Toolbox documentation, aims to solve the following
% problem:
%
% Modify the filtering example (COMMDOC_RRC) so that it
% includes convolutional coding and decoding, given the
% constraint lengths and generator polynomials of the
% convolutional code.

% Copyright 1996-2013 The MathWorks, Inc.

%% Setup
% Define parameters
M = 16;                     % Size of signal constellation
k = log2(M);                % Number of bits per symbol
n = 5e5;                    % Number of bits to process
nSamp = 4;                  % Oversampling rate

%% Create Modulator and Demodulator
hMod = modem.qammod(M);         % Create a 16-QAM modulator
hMod.InputType = 'Bit';         % Accept bits as inputs
hMod.SymbolOrder = 'Gray';      % Accept bits as inputs
hDemod = modem.qamdemod(hMod);  % Create a 16-QAM based on the modulator

%% Design a Raised Cosine Filter
% Filter-related parameters
Span = 10;               % Filter span in symbols
N = Span * nSamp;        % Filter order
rolloff = 0.25;          % Roloff factor of filter

% Create a square-root raised cosine filter
rrcFilter=rcosdesign(rolloff,Span,nSamp);                                

% Plot impulse response
fvtool(rrcFilter, 'impulse')

%% Design a Convolutional Encoder
% Define a convolutional coding trellis
t = poly2trellis([5 4],[23 35 0; 0 5 13]); % Trellis
codeRate = 2/3;

%% Signal Source
% Create a binary data stream as a column vector
x = randi([0 1],n,1); % Random binary data stream

%% Encoding
% Convolutionally encode the binary data
code = convenc(x,t); % Encode

%% Modulation
% Modulate using 16-QAM
y = modulate(hMod,code);

%% Transmitted Signal
% Upsample the signal and apply square-root raised cosine filter
yTx = upfirdn(y,rrcFilter,nSamp,1);
yTx = yTx(1:n*3/2);

% Create eye diagram for part of filtered signal
ploteye(yTx(N/2:2000), nSamp);

%% Channel
% Send signal over an AWGN channel
EbNo = 10; % In dB
SNR = EbNo + 10*log10(k*codeRate) - 10*log10(nSamp);
yNoisy = awgn(yTx,SNR,'measured');

%% Received Signal
% Apply square-root raised cosine filter and downsample
yRx = upfirdn(yNoisy,rrcFilter,1,nSamp);

delay = N/(nSamp*2);                % Group delay (# of input samples)
yRx = yRx(Span+1:end-2*Span);   % Account for delay

%% Scatter Plot
% Create scatter plot of noisy signal and ideal constellation points
hScatter = commscope.ScatterPlot;            % Create a scatter plot scope
hScatter.Constellation = hMod.Constellation; % Set expected constellation
hScatter.SamplesPerSymbol = nSamp;           % Set oversampling rate
hScatter.PlotSettings.Constellation = 'on';  % Display ideal constellation
update(hScatter, yRx)                 % Send received signal to the scope
title('Received Signal');

%% Demodulation
% Demodulate signal using 16-QAM
z = demodulate(hDemod,yRx);

%% Decoder
% Decode the convolutional code
tb = 16;                             % Traceback length for decoding
numCodeWords = floor(length(z)*2/3); % Number of complete codewords
z = vitdec(z(1:numCodeWords*3/2),t,tb,'cont','hard');    
                                     % Decode

%% BER Computation
% Compare x and z to obtain the number of errors and
% the bit error rate
decdelay = 2*tb;      % Decoder delay, in bits
[number_of_errors,bit_error_rate] = ...
    biterr(x(1:end-decdelay-ceil(4*delay*k*codeRate)),z(decdelay+1:end))

