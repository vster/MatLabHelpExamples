t = 0:0.001:1-0.001;
x = 3*cos(2*pi*100*t)+0.01*cos(2*pi*200*t)+0.005*cos(2*pi*300*t);
tharmdist = 10*log10((0.01^2+0.005^2)/3^2)
r = thd(x)