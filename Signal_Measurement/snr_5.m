rng default
Fi = 2500; Fs = 48e3; N = 1024;
x = sin(2*pi*Fi/Fs*(1:N)) + 0.00001*randn(1,N);
w = kaiser(numel(x),38);
[Pxx, F] = periodogram(x,w,numel(x),Fs);
SNR = snr(Pxx,F,'psd')