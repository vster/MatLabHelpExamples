fs = 1000;                % Sampling frequency
t = (0:fs)/fs;            % One second worth of samples
A = [1 2];                % Sinusoid amplitudes
f = [150;140];            % Sinusoid frequencies
xn = A*sin(2*pi*f*t) + 0.1*randn(size(t));
[Pxx1,F1] = pmtm(xn,4,fs);
plot(F1,10*log10(Pxx1))

[Pxx2,F2] = pmtm(xn,1.5,fs);
plot(F2,10*log10(Pxx2))