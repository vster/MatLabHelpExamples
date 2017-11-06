fs = 1000;               % Sampling frequency
t = (0:fs)/fs;           % One second worth of samples
A = [1 2];               % Sinusoid amplitudes
f = [150;140];           % Sinusoid frequencies
xn = A*sin(2*pi*f*t) + 0.1*randn(size(t));
pwelch(xn,hamming(256),128,1024,fs);

pburg(xn,14,1024,fs)