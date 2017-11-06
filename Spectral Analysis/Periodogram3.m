fs = 1000;                  % Sampling frequency
t = (0:fs/10)./fs;          % One-tenth second worth of samples
A = [1 2];                  % Sinusoid amplitudes
f = [150;140];              % Sinusoid frequencies
xn = A*sin(2*pi*f*t) + 2*randn(size(t));
[Pxx,F] = periodogram(xn,rectwin(length(xn)),length(xn),fs);
plot(F,10*log10(Pxx))