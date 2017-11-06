n = 0:15;
x = cos(pi/4*n);

rmsval = rms(x)

t = 0:0.01:1;
x = 2*square(2*pi*10*t);
stem(t,x,'markerfacecolor',[0 0 1]); axis([0 1 -2.5 2.5]);

rmsval = rms(x)

t = 0:0.001:(10*0.1);
pulsewidth = 0.025;
pulseperiods = [0:10]*0.1;
x = pulstran(t,pulseperiods,@rectpuls,pulsewidth);
plot(t,x); axis([0 1 -0.5 1.5]);
xlabel('Seconds'); ylabel('Amplitude');

rmsval = rms(x)
thrms = sqrt(1/4)