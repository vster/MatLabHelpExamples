% SYNCCARRIERFREQMSKSIGNALRECOVERY Recover the carrier frequency using a
% combination of the 2P-power method and the delay-and-multiply scheme. This
% script is used commMSKSignalRecovery.m.

%   Copyright 2010 The MathWorks, Inc.
%   $Revision: 1.1.8.1 $ $Date: 2013/12/27 02:23:11 $


%% Calculate the frequency shift estimate

% Isolate the frequency using the 2P-power method
P = 2;
currInstFreq = rxSym.^(2*P);  % Current instantaneous frequency exponential

prevInstFreq = step(hDelayInstFreq, currInstFreq);  % Previous instantaneous 
                                                    % frequency exponential

% Subtract current instantaneous frequency from the previous instantaneous
% frequency to calculate the frequency shift for the current symbol
freqShiftEst = currInstFreq .* conj(prevInstFreq);
% Average over 1 frame
freqShiftEst = mean(freqShiftEst);
% Moving average over 100 frames
freqShiftEst = step(hMovAve, freqShiftEst);
% Get the instantaneous frequency shift estimate and remove the 2*P factor
freqShiftEst = angle(freqShiftEst) / (2*P);
% Convert digital frequency to Hertz
freqShiftEst = freqShiftEst / (2*pi*Ts);

%% Apply frequency correction

freqCorr = repmat(-freqShiftEst*Ts, samplesPerFrame, 1);
% Calculate cumulative phase shift
freqCorr = step(hCumSum, freqCorr);
% Apply frequency shift correction
rxSym = rxSym .* exp(1i*2*pi*freqCorr);
