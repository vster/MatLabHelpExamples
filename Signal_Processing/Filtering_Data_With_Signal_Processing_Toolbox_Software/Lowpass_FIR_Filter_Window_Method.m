rng default;
Fs = 1000;
t = linspace(0,1,Fs);
x = cos(2*pi*100*t)+0.5*randn(size(t));

fc = 150;
Wn = (2/Fs)*fc;
b = fir1(20,Wn,'low',kaiser(21,3));
fvtool(b,1,'Fs',Fs);

y = filter(b,1,x);
plot(t(1:100),x(1:100),'k');
hold on;
plot(t(1:100),y(1:100),'r','linewidth',2);
legend('Original Signal','Filtered Data','Location','SouthEast');
xlabel('Seconds'); ylabel('Amplitude');

Fs = 1000;
Hd = designfilt('lowpassfir','FilterOrder',20,'CutoffFrequency',150, ...
       'DesignMethod','window','Window',{@kaiser,3},'SampleRate',Fs);
   
y1 = filter(Hd,x);
plot(t(1:100),x(1:100),'k');
hold on;
plot(t(1:100),y1(1:100),'r','linewidth',2);
legend('Original Signal','Filtered Data','Location','SouthEast');
xlabel('Seconds'); ylabel('Amplitude');