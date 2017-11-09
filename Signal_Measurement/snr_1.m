rng default
Tpulse = 20e-3;
Fs = 10e3;
t = -1:1/Fs:1;
x = rectpuls(t,Tpulse);
y = 0.00001*randn(size(x));
s = x + y;
pulseSNR = snr(x,s-x)