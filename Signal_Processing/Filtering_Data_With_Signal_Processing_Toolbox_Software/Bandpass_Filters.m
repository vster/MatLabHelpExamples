rng default;
Fs =1;
n = 1:365;
x = cos(2*pi*(1/7)*n)+cos(2*pi*(1/30)*n-pi/4);
trend = 3*sin(2*pi*(1/1480)*n);
y = x+trend+0.5*randn(size(n));
subplot(211);
plot(n,y); xlabel('Days'); set(gca,'xlim',[1 365]);
grid on;
subplot(212);
[pxx,f] = periodogram(y,[],length(y),Fs);
plot(f,10*log10(pxx));
xlabel('Cycles/day'); ylabel('dB'); grid on;

Hd1 = designfilt('bandpassfir', ...
    'StopbandFrequency1',1/60,'PassbandFrequency1',1/40, ...
    'PassbandFrequency2',1/4 ,'StopbandFrequency2',1/2 , ...
    'StopbandAttenuation1',10,'PassbandRipple',1, ...
    'StopbandAttenuation2',10,'DesignMethod','equiripple','SampleRate',Fs);
Hd2 = designfilt('bandpassiir', ...
    'StopbandFrequency1',1/60,'PassbandFrequency1',1/40, ...
    'PassbandFrequency2',1/4 ,'StopbandFrequency2',1/2 , ...
    'StopbandAttenuation1',10,'PassbandRipple',1, ...
    'StopbandAttenuation2',10,'DesignMethod','butter','SampleRate',Fs);

fprintf('The order of the FIR filter is %d\n',filtord(Hd1));
fprintf('The order of the IIR filter is %d\n',filtord(Hd2));
[phifir,w] = phasez(Hd1,[],1);
[phiiir,w] = phasez(Hd2,[],1);
figure
plot(w,unwrap(phifir),'b'); hold on;
plot(w,unwrap(phiiir),'r'); grid on;
xlabel('Cycles/Day'); ylabel('Radians');
legend('FIR Equiripple Filter','IIR Butterworth Filter');

Hdlow = designfilt('lowpassfir', ...
    'PassbandFrequency',1/4,'StopbandFrequency',1/2, ...
    'PassbandRipple',1,'StopbandAttenuation',10, ...
    'DesignMethod','equiripple','SampleRate',1);

yfir = filter(Hd1,y);
yiir = filter(Hd2,y);
ylow = filter(Hdlow,y);

[pxx,f] = periodogram(yiir,[],length(yiir),Fs);
plot(f,10*log10(pxx));
xlabel('Cycles/day'); ylabel('dB'); grid on;

clf
plot(n(1:120),yfir(1:120),'b');
hold on;
plot(n(1:120),yiir(1:120),'r');
xlabel('Days'); axis([1 120 -2.8 2.8]);
legend('FIR bandpass filter output','IIR bandpass filter output',...
    'Location','SouthEast');

clf
plot(n,x,'k');
hold on;
plot(n,ylow,'r'); set(gca,'xlim',[1 365]);
legend('7-day and 30-day cycles','FIR lowpass filter output',...
    'Location','NorthWest');
xlabel('Days');