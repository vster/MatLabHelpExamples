% CONFIGUREMSKSIGNALRECOVERY Initialize system parameters as well as create
% and configure System objects used in commMSKSignalRecovery.m

%   Copyright 2010 The MathWorks, Inc.
%   $Revision: 1.1.8.1 $ $Date: 2013/12/27 02:23:08 $


%%
% Initialize system parameters

Ts = 1/280000;    % Sample time of each symbol / bit
samplesPerSymbol = 14;    % Up-sample factor
trDepth = 16;             % The traceback depth of the Viterbi algorithm
samplesPerFrame = 1000;
numFrames = 100;          % End of simulation criterion
% Initialize the variables used to store the history of timing, carrier
% frequency, and phase estimates
timEstHist = zeros(1,numFrames);
freqShiftEstHist = zeros(1,numFrames);
phEstHist = zeros(1,numFrames);

%%
% Create an MSK modulator (hMod) System object and a matching MSK
% demodulator (hDemod) System object. You configure the samplesPerSymbol
% property to generate 14 samples for each modulated symbol. The MSK
% modulator accepts bit-valued inputs and the demodulator accepts bit-valued
% outputs.

hMod = comm.MSKModulator('BitInput',true, ...
                'SamplesPerSymbol',samplesPerSymbol);
hDemod = comm.MSKDemodulator('SamplesPerSymbol',1, ...
                  'TracebackDepth',trDepth, ...
                  'BitOutput',true);

%%
% Create a bit error rate calculator (hBER) System object to compare the
% demodulated bit data with the original source data, yielding bit error
% statistics. The output of the error rate calculator System object is a
% three-element vector containing the calculated error rate, the number of
% errors observed, and the amount of data processed. The MSK demodulator
% System object uses the Viterbi algorithm which causes a delay equal to the
% traceback depth (trDepth), while the MSK timing synchronizer System object
% incurs a delay of 2 symbols. Thus, the 'ReceiveDelay' property is set to
% 'trDepth + 2'.

hBER = comm.ErrorRate('ReceiveDelay',trDepth + 2);
