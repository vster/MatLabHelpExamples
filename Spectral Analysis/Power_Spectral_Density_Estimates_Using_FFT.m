rng default;
Fs = 1000;
t = 0:1/Fs:1-1/Fs;
x = cos(2*pi*100*t)+randn(size(t));

N = length(x);
xdft = fft(x);
xdft = xdft(1:N/2+1);
psdx = (1/(Fs*N)).*abs(xdft).^2;
psdx(2:end-1) = 2*psdx(2:end-1);
freq = 0:Fs/length(x):Fs/2;
plot(freq,10*log10(psdx)); grid on;
title('Periodogram Using FFT');
xlabel('Frequency (Hz)'); ylabel('Power/Frequency (dB/Hz)');

figure;
[psdestx,Fxx] = periodogram(x,rectwin(length(x)),length(x),Fs);
plot(Fxx,10*log10(psdestx)); grid on;
xlabel('Hz'); ylabel('Power/Frequency (dB/Hz)');
title('Periodogram Power Spectral Density Estimate');
max(psdx'-psdestx)