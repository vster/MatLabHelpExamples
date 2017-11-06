% This example shows how to measure the adjacent channel power ratio (ACPR) 
% from a baseband, 50 kbps QPSK signal. ACPR is the ratio of signal power 
% measured in an adjacent frequency band to the power from the same signal 
% measured in its main band. The number of samples per symbol is set to four.

% Set the random number generator so that results are repeatable.

prevState = rng;
rng(577)

% Set the samples per symbol (sps) and channel bandwidth (bw) parameters.

sps = 4;
bw = 50e3;

% Generate 10,000 4-ary symbols for QSPK modulation.

data = randi([0, 3],10000,1);

% Construct a QPSK modulator and then modulate the input data.

hMod = comm.QPSKModulator;
x = step(hMod, data);

% Apply rectangular pulse shaping to the modulated signal. This type of pulse 
% shaping is typically not done in practical system but is used here for illustrative purposes.

y = rectpulse(x, sps);

% Construct an ACPR System object.

hACPR = comm.ACPR('SampleRate',bw*sps,...
    'MainChannelFrequency',0,...
    'MainMeasurementBandwidth',bw,...
    'AdjacentChannelOffset',50e3,...
    'AdjacentMeasurementBandwidth',bw,...
    'MainChannelPowerOutputPort', true,...
    'AdjacentChannelPowerOutputPort',true);

% Use the step method of the comm.ACPR System object to output the ACPR, 
% the main channel power, and the adjacent channel power for the signal, y.

[ACPR, mainPower, adjPower] = step(hACPR, y)

% Change the frequency offset to 75 kHz and determine the ACPR. Since the 
% AdjacentChannelOffset property is nontunable, you must first release hACPR. 
% Observe that the ACPR improves when the channel offset is increased.

release(hACPR)
hACPR.AdjacentChannelOffset = 75e3;
ACPR = step(hACPR, y)

% Reset hACPR and specify a 50 kHz adjacent channel offset.

release(hACPR)
hACPR.AdjacentChannelOffset = 50e3;

% Create a raised cosine filter and filter the modulated signal.

hFilt = comm.RaisedCosineTransmitFilter('OutputSamplesPerSymbol', sps);
z = step(hFilt, x);

% Measure the ACPR for the filtered signal, z . You can see that the ACPR improves 
% from -9.5 dB to -17.7 dB when raised cosine pulses are used.

ACPR = step(hACPR, z)

% Plot the adjacent channel power ratios for a range of adjacent channel offsets. 
% Set the channel offsets to range from 30 kHz to 70 kHz in 10 kHz steps. 
% Recall that you must first release hACPR to change the offset.

freqOffset = 1e3*(30:5:70);
release(hACPR)
hACPR.AdjacentChannelOffset = freqOffset;

% Determine the ACPR values for the signals with rectangular and raised cosine pulse shapes.

ACPR1 = step(hACPR, y);
ACPR2 = step(hACPR, z);

% Plot the adjacent channel power ratios.

plot(freqOffset/1000,ACPR1,'*-',freqOffset/1000, ACPR2,'o-')
xlabel('Adjacent Channel Offset (kHz)')
ylabel('ACPR (dB)')
legend('Rectangular','Raised Cosine','location','best')
grid

% Return the random number generator to its initial state.

rng(prevState)
