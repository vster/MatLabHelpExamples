t = 0:0.001:1-0.001;
fs = 1000;
x = 2*cos(2*pi*100*t)+0.01*cos(2*pi*200*t)+ ...
    0.005*cos(2*pi*300*t)+0.0025*sin(2*pi*400*t);
[pxx,f] = periodogram(x,rectwin(length(x)),length(x),fs);
r = thd(pxx,f,3,'psd');
