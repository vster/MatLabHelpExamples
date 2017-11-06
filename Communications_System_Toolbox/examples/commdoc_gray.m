%% Incorporating Gray Coding
% This example, described in the Getting Started chapter of the
% Communications Toolbox documentation, aims to solve the following
% problem:
%
% Modify the modulation example (COMMDOC_MOD) so that it uses
% a Gray-coded signal constellation.

% Copyright 1996-2009 The MathWorks, Inc.

%% Setup
% Define parameters.
M = 16;                     % Size of signal constellation
k = log2(M);                % Number of bits per symbol
n = 3e4;                    % Number of bits to process
nSamp = 1;                  % Oversampling rate

%% Create Modulator and Demodulator
hMod = modem.qammod(M);         % Create a 16-QAM modulator
hMod.InputType = 'Bit';         % Accept bits as inputs
hMod.SymbolOrder = 'Gray';      % Accept bits as inputs
hDemod = modem.qamdemod(hMod);  % Create a 16-QAM based on the modulator

%% Signal Source
% Create a binary data stream as a column vector.
x = randi([0 1],n,1); % Random binary data stream

%% Modulation
% Modulate using 16-QAM.
y = modulate(hMod,x);

%% Transmitted Signal
yTx = y;

%% Channel
% Send signal over an AWGN channel.
EbNo = 10; % In dB
SNR = EbNo + 10*log10(k) - 10*log10(nSamp);
yNoisy = awgn(yTx,SNR,'measured');

%% Received Signal
yRx = yNoisy;

%% Scatter Plot
% Create scatter plot of noisy signal and ideal constellation points
hScatter = commscope.ScatterPlot;            % Create a scatter plot scope
hScatter.Constellation = hMod.Constellation; % Set expected constellation
hScatter.SamplesPerSymbol = nSamp;           % Set oversampling rate
hScatter.PlotSettings.Constellation = 'on';  % Display ideal constellation
update(hScatter, yRx(1:5e3))                 % Send received signal to the scope
title('Received Signal');

%% Demodulation
% Demodulate signal using 16-QAM.
z = demodulate(hDemod,yRx);

%% BER Computation
% Compare x and z to obtain the number of errors and
% the bit error rate.
[number_of_errors,bit_error_rate] = biterr(x,z)
