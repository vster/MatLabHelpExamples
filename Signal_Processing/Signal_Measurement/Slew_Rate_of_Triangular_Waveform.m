t = 0:0.01:1;
x = 2*t;
x = [x fliplr(x)];
tnew = [t t+1.01];
plot(tnew,x); xlabel('Time');
ylabel('Amplitude');

s = slewrate(x,100)



t = 0:0.01:1;
x = 1/2*t;
x = [x fliplr(x)];
tnew = [t t+1.01];
plot(tnew,x);  xlabel('Time');
ylabel('Amplitude');

s = slewrate(x,100)


t = 0:0.01:1;
x = 2*t;
t1 = 1:0.01:5;
x1 = -1/2*(t1-1)+2;
y = [x x1];
tnew = [t t1];
plot(tnew,y);  xlabel('Time');
ylabel('Amplitude');

s = slewrate(y,100)

