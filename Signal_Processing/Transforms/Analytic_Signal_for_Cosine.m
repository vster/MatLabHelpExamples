t = 0:1e-4:1;
x = 2.5+cos(2*pi*100*t);

y = hilbert(x);
plot(t,real(y),'b','linewidth',2);
hold on;
plot(t,imag(y),'r','linewidth',2);
set(gca,'xlim',[0 0.1]); grid on;
xlabel('Seconds');

plot3(t(1:1e3),real(y(1:1e3)),imag(y(1:1e3)));
xlabel('Time','fontsize',14); ylabel('Re{z(t)}','fontsize',14);
zlabel('Im{z(t)}','fontsize',14);