Fs = 1000;
t = 0:1/Fs:1-1/Fs;
rng default;
x = cos(2*pi*100*t)+sin(2*pi*200*t)+0.5*randn(size(t));
y = 0.5*cos(2*pi*100*t-pi/4)+0.35*sin(2*pi*200*t-pi/2)+0.5*randn(size(t));

[Pxy,F] = mscohere(x,y,hamming(100),80,100,Fs);
plot(F,Pxy,'linewidth',2); title('Magnitude-squared Coherence');
xlabel('Hz'); grid on;

[Cxy,F] = cpsd(x,y,hamming(100),80,100,Fs);
figure;
plot(F,-angle(Cxy),'linewidth',2); title('Cross Spectrum Phase');
xlabel('Radians');
set(gca,'xtick',[100 200]);
set(gca,'ytick',[-pi -pi/2 -pi/4 0 pi/4 pi/2 pi]);
grid on;