fs = 1000;                % Sampling frequency
t = (0:fs)/fs;            % One second worth of samples
A = [1 2 3];                % Sinusoid amplitudes (row vector)
f = [150;140;350];            % Sinusoid frequencies (column vector)
xn = A*sin(2*pi*f*t) + 0.1*randn(size(t));

[Pxx,F] = periodogram(xn,hamming(length(xn)),length(xn),fs);
plot(F,10*log10(Pxx))
xlabel('Hz'); ylabel('dB');
title('Modified Periodogram Power Spectral Density Estimate');
grid