VmaxPk = 2;       % Maximum operating voltage
Fi = 2000;        % Sinusoidal frequency of 2 kHz
Fs = 44.1e3;      % Sample rate of 44.1kHz
Tstop = 50e-3;    % Duration of sinusoid
t = 0:1/Fs:Tstop; % Input time vector

% Use the maximum allowable voltage of the amplifier
inputVmax = VmaxPk*sin(2*pi*Fi*t);
outputVmax = helperHarmonicDistortionAmplifier(inputVmax);

plot(t, outputVmax);
xlabel('Time')
ylabel('Output Voltage');
axis([0 5e-3 -2.5 2.5]);
title('Amplifier output');

helperPlotPeriodogram(outputVmax, Fs, 'power','annotate');