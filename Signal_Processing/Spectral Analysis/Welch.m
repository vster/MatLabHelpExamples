fs = 1000;             % Sampling frequency
t = (0:1*fs)./fs;    % 301 samples
A = [2 8];             % Sinusoid amplitudes (row vector)
f = [150;140];         % Sinusoid frequencies (column vector)
xn = A*sin(2*pi*f*t) + 5*randn(size(t));
[Pxx,F] = periodogram(xn,rectwin(length(xn)),length(xn),fs);
plot(F,10*log10(Pxx))

[Pxx,F] = pwelch(xn,hamming(150),75,150,fs);
plot(F,10*log10(Pxx)); xlabel('Hz'); ylabel('dB');
title('Welch''s Overlapped Segment Averaging PSD Estimate');

[Pxx,F] = pwelch(xn,rectwin(100),75,512,fs);
plot(F,10*log10(Pxx))