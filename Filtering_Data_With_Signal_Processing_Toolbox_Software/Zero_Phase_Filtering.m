rng default;
Fs = 1000;
t = linspace(0,1,Fs);
x = cos(2*pi*100*t)+0.5*randn(size(t));
% Using fir1
fc = 150;
Wn = (2/Fs)*fc;
b = fir1(20,Wn,'low',kaiser(21,3));
% Using designfilt
Hd = designfilt('lowpassfir','FilterOrder',20,'CutoffFrequency',150, ...
       'DesignMethod','window','Window',{@kaiser,3},'SampleRate',Fs);
   
yout = filter(Hd,x);
xin = cos(2*pi*100*t);
plot(t(1:100),xin(1:100),'k');
hold on; grid on;
plot(t(1:100),yout(1:100),'r','linewidth',2);
xlabel('Seconds'); ylabel('Amplitude');
legend('Input Sine Wave','Filtered Data',...
    'Location','NorthEast');

fvtool(Hd,'analysis','grpdelay');

yzp = filtfilt(Hd,x);
plot(t(1:100),xin(1:100),'k');
hold on;
plot(t(1:100),yout(1:100),'r','linewidth',2);
plot(t(1:100),yzp(1:100),'b','linewidth',2);
xlabel('Seconds'); ylabel('Amplitude');
legend('100-Hz Sine Wave','Filtered Signal','Zero-phase Filtering',...
    'Location','NorthEast');