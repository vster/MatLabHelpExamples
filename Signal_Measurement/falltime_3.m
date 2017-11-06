% Determine the fall time, reference-level instants, and reference levels in a 2.3 V clock waveform sampled at 4 MHz.

% Load the 2.3 V clock waveform along with the sampling instants.

load('negtransitionex.mat','x','t');

% Determine the falltime, reference-level instants, and reference levels.

[F,LT,UT,LL,UL] = falltime(x,t);

% Plot the waveform in microseconds with the upper and lower reference levels and reference level instants. Show that the fall time is the difference between the lower- and upper-reference level instants.

plot(t.*1e6,x);
xlabel('microseconds'); ylabel('Volts');
hold on; grid on;
plot(LT.*1e6,LL,'ro','markerfacecolor',[1 0 0]);
plot(UT.*1e6,UL,'ro','markerfacecolor',[1 0 0]);
fprintf('Rise time is %1.4f microseconds.\n',(LT-UT)*1e6)