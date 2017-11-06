t = 0:1e-4:1;
x = [1+cos(2*pi*50*t)].*cos(2*pi*1000*t);
plot(t,x); set(gca,'xlim',[0 0.1]);
xlabel('Seconds'); ylabel('Amplitude');

y = hilbert(x);
env = abs(y);
plot(t,x); hold on;
plot(t,abs(y),'r','linewidth',2);
plot(t,-abs(y),'r','linewidth',2);
set(gca,'xlim',[0 0.1]);
xlabel('Seconds'); ylabel('Amplitude');