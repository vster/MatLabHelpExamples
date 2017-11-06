t = 0:0.001:1-0.001;
x = cos(2*pi*100*t)+randn(size(t));
pband = bandpower(x,1000,[50 150]);
ptot = bandpower(x,1000,[0 500]);
per_power = 100*(pband/ptot)