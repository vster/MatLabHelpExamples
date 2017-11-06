rng default;
n = 0:999;
x = exp(1j*pi/4*n)+1/sqrt(2)*randn(size(n))+1j*1/sqrt(2)*randn(size(n));

N = length(x);
xdft = fft(x);
psdx = (1/(2*pi*N)).*abs(xdft).^2;
freq = 0:(2*pi)/N:2*pi-(2*pi)/N;
plot(freq./pi,10*log10(psdx)); grid on;
title('Periodogram Using FFT');
xlabel('Normalized Frequency');
ylabel('Power/Frequency (dB/rad/sample)');

[psdestx,Fxx] = periodogram(x,rectwin(length(x)),length(x),'twosided');
figure;
plot(Fxx./pi,10*log10(psdestx));
grid on; xlabel('Normalized Frequency');
ylabel('Power/Frequency (dB/rad/sample)');
title('Periodogram Power Spectral Density Estimate');
max(psdx'-psdestx)