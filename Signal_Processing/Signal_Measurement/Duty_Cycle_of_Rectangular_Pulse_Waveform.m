Fs = 1e9;
t = 0:1/Fs:(10*4e-6);
pulsewidth = 1e-6;
pulseperiods = [0:10]*4e-6;
x = pulstran(t,pulseperiods,@rectpuls,pulsewidth);
plot(t.*1e6,x); axis([0 40 -0.5 1.5]);
xlabel('\mus'); ylabel('Amplitude');

D = dutycycle(x,Fs)

dutycycle(x,Fs);

pulsewidths = 1e-6:1e-6:3e-6;
for nn = 1:length(pulsewidths)
    x = pulstran(t,pulseperiods,@rectpuls,pulsewidths(nn));
    plot(t.*1e6,x); axis([0 40 -0.5 1.5]);
    xlabel('\mus'); ylabel('Amplitude');
    D = dutycycle(x,Fs);
    title(['Duty cycle is ' num2str(mean(D)) ]);
    pause(1);
end