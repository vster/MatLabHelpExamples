% Load the 2.3 V clock data with sampling instants. Plot the waveform.

load('transitionex.mat','x','t');
plot(t,x);

% Determine the rise time using the 20% and 80% reference levels.

R = risetime(x,'PercentReferenceLevels',[20 80]);