% Load the 2.3 V clock waveform along with the sampling instants.

load('transitionex.mat','x','t');

% Determine the rise time, reference-level instants, and reference levels.

[R,LT,UT,LL,UL] = risetime(x,t);

% Plot the waveform in microseconds with the lower- and upper-reference levels and reference-level instants. Show that the rise time is the difference between the upper- and lower-reference level instants.

plot(t.*1e6,x);
xlabel('microseconds'); ylabel('Volts');
hold on; grid on;
plot(LT.*1e6,LL,'ro','markerfacecolor',[1 0 0]);
plot(UT.*1e6,UL,'ro','markerfacecolor',[1 0 0]);
fprintf('Rise time is %1.4f microseconds.\n',(UT-LT)*1e6)