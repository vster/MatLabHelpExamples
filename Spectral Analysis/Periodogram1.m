fs = 1000;                 % Sampling frequency
t = (0:fs/10)/fs;          % One-tenth second worth of samples
A = [1 2 3];                 % Sinusoid amplitudes
f = [150;140;240];             % Sinusoid frequencies
xn = A*sin(2*pi*f*t) + 0.1*randn(size(t));
[Pxx,F] = periodogram(xn,hann(length(xn)),length(xn),fs);
plot(F,10*log10(Pxx))