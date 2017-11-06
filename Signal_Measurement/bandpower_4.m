Fs = 1000;
t = 0:1/Fs:1-0.001;
x = cos(2*pi*100*t)+randn(size(t));
[Pxx,F] = periodogram(x,rectwin(length(x)),length(x),Fs);
pband = bandpower(Pxx,F,[50 150],'psd');
ptot = bandpower(Pxx,F,'psd');
per_power = 100*(pband/ptot)