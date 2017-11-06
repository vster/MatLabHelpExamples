% RSCodingConfigExample Initialization script for Reed-Solomon doc examples.
%
%   This MATLAB file is in support of various doc examples and may be removed in
%   a future release.
%
%   Initialize modulator, demodulator, AWGNChannel, and error rate
%   measurement System objects. Define simulation value for uncoded Eb/No
%   ratio, and set simulation stop criteria for the RS coding examples with
%   erasures, punctures, and shortening.

%   Copyright 2010-2014 The MathWorks, Inc.

% If initialization is called by the example, then set a single uncoded
% Eb/No value, and set the simulation stop criteria.
if ~exist('initFlagRSDemo', 'var') || initFlagRSDemo
  EbNoUncoded = 15; % dB
    
  % Set the simulation stop criteria by defining the target number of errors
  % and maximum number of transmissions.
  targetErrors = 500;
  maxNumTransmissions = 5e6;  
end

%% Rectangular 64-QAM Modulation
% Create a rectangular 64-QAM modulator System object. Set the SymbolMapping
% to 'Gray' for Gray coding and set the BitInput property to false to
% specify that the modulator's input is integer symbols.

M = 64; % Modulation order
hMod = comm.RectangularQAMModulator(M, 'SymbolMapping', 'Gray',...
  'BitInput', false);

% Create a rectangular 64-QAM demodulator System object with same settings
% as the modulator. Set the BitOutput property to false so that the
% demodulator outputs integer symbols.
hDemod = comm.RectangularQAMDemodulator(M, 'SymbolMapping', 'Gray',...
  'BitOutput', false);

%% AWGN Channel
% Create an additive white Gaussian noise (AWGN) channel System object. Set
% the NoiseMethod property to 'Signal to noise ratio (Eb/No)' to specify the
% noise level using the energy per bit to noise power spectral density ratio
% (Eb/No) in dB. 
hChan = comm.AWGNChannel('NoiseMethod', 'Signal to noise ratio (Eb/No)');

% We assume no upsampling so the number of samples per symbol is 1. The
% signal power for rectangular 64-QAM is 42 Watts, so we set the SignalPower
% property of the channel to this value.
hChan.SamplesPerSymbol = 1;
hChan.SignalPower = 42; 

% The number of bits per symbol is equal to log2(M). We need to set the
% BitsPerSymbol property of the AWGN channel System object so that it knows
% how to distribute noise evenly across the symbol samples.
hChan.BitsPerSymbol = log2(M);

%% Error rate measurement
% Create two error rate measurement System objects, one to measure the
% channel bit error rate (BER), and the other to measure the coded BER.
% Since the inputs and outputs of the modulator and demodulator are integer
% symbols, and we want to measure bit error rates, we also need to create
% integer to bit converters.

% Error rate measurement System object for channel BER
hChanBERCalc = comm.ErrorRate; 
% Error rate measurement System object for coded BER
hCodedBERCalc = comm.ErrorRate;
% Integer to bit converters. Set the BitsPerInteger property to log2(M)=6 to
% convert integers to 6-bit words
hIntToBit1 = comm.IntegerToBit('BitsPerInteger', log2(M));
hIntToBit2 = comm.IntegerToBit('BitsPerInteger', log2(M));

% We also create a cumulative sum System object to log the number of errors
% corrected by the RS decoder.
hCumSum = dsp.CumulativeSum;


