rng default;
n = 0:999;
x = cos(pi/4*n)+randn(size(n));

N = length(x);
xdft = fft(x);
xdft = xdft(1:N/2+1);
psdx = (1/(2*pi*N)).*abs(xdft).^2;
psdx(2:end-1) = 2*psdx(2:end-1);
freq = 0:(2*pi)/N:pi;
plot(freq./pi,10*log10(psdx)); grid on;
title('Periodogram Using FFT');
xlabel('Normalized Frequency');
ylabel('Power/Frequency (dB/rad/sample)');

figure;
[psdestx,Fxx] = periodogram(x,rectwin(length(x)),length(x));
plot(Fxx./pi,10*log10(psdestx));
xlabel('Hz'); ylabel('Power/Frequency (dB/Hz)');
title('Periodogram Power Spectral Density Estimate');
xlabel('Normalized Frequency'); grid on;
ylabel('Power/Frequency (dB/rad/sample)');
max(psdx'-psdestx)