function [ber, numBits] = commdoc_bertool(EbNo, maxNumErrs, maxNumBits)
%COMMDOC_BERTOOL BERTool example in Getting Started documentation.
%   This example, described in the Getting Started chapter of the
%   Communications Toolbox documentation, aims to solve the following
%   problem:
%
%   Modify the modulation example in Incorporating Gray Coding
%   (COMMDOC_GRAY) so that it computes the BER for integer values
%   of EbNo between 0 and 7. Plot the BER as a function of EbNo
%   using a logarithmic scale for the vertical axis.

%   Copyright 1996-2011 The MathWorks, Inc.

% Import Java class for BERTool.
import com.mathworks.toolbox.comm.BERTool;

% Initialize variables related to exit criteria.
% berVec stores updated values of ber, total number of bit errors, and
% total number of bits processed.
berVec = zeros(1,3); 

%% Setup
% Define parameters.
M = 16;                     % Size of signal constellation
k = log2(M);                % Number of bits per symbol
n = 1000;                   % Number of bits to process
nSamp = 1;                  % Oversampling rate

%% Create Modulator and Demodulator System Objects
hMod = comm.RectangularQAMModulator(M, ...
    'BitInput', true);         % Create a 16-QAM modulator
hDemod = comm.RectangularQAMDemodulator (M, ...
    'BitOutput', true);  % Create a 16-QAM based on the modulator

%% Create AWGNChannel System object
% Create an AWGNChannel System object and set its NoiseMethod property to
% 'Signal to noise ratio (SNR)'.
hChan = comm.AWGNChannel('NoiseMethod', 'Signal to noise ratio (SNR)');
%EbNo = 10; % In dB % COMMENT OUT FOR BERTOOL
SNR = EbNo + 10*log10(k) - 10*log10(nSamp);
hChan.SNR = SNR;

%% Create ErrorRate calculator System object
% Create an ErrorRate calculator System object to compare decoded bits to
% the original transmitted bits.
hErrorCalc = comm.ErrorRate;

% Simulate until number of errors exceeds maxNumErrs
% or number of bits processed exceeds maxNumBits.
while((berVec(2) < maxNumErrs) && (berVec(3) < maxNumBits))

   % Check if the user clicked the Stop button of BERTool.
   if (BERTool.getSimulationStop)
      break;
   end

   % --- Proceed with simulation.
   
   %% Signal Source
   % Create a binary data stream as a column vector.
   x = randi([0 1],n,1); % Random binary data stream
   
   %% Modulation
   % Modulate using 16-QAM.
   y = step(hMod,x);
   
   %% Transmitted Signal
   yTx = y;
   
   %% Channel
   % Calculate and set signal power.
   % Send signal over an AWGN channel.
    hChan.SignalPower = (yTx' * yTx)/ length(yTx);
    yNoisy = step(hChan, yTx);
   
   %% Received Signal
   yRx = yNoisy;
   
   %% Demodulation
   % Demodulate signal using 16-QAM.
   z = step(hDemod,yRx);

   %% BER Computation
   % Compare x and z to obtain the number of errors and
   % the bit error rate.
   berVec = step(hErrorCalc, x, z);

end % End of loop

ber = berVec(1);
numBits = berVec(3);
   