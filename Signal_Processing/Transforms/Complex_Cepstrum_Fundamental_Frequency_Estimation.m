load mtlb;

segmentlen = 100;
noverlap = 90;
NFFT = 128;
[y,f,t,p] = spectrogram(mtlb,segmentlen,noverlap,NFFT,Fs);
surf(t,f,10*log10(abs(p)),'EdgeColor','none');
axis xy; axis tight; colormap(jet); view(0,90);
xlabel('Time');
ylabel('Frequency (Hz)');

dt = 1/Fs;
I0 = round(0.1/dt);
Iend = round(0.25/dt);
x = mtlb(I0:Iend);

c  = cceps(x);

t = 0:dt:length(x)-dt;
plot(t(15:75).*1e3,c(15:75)); xlabel('msec');
[~,I] = max(c(15:55));
fprintf('Complex cepstrum F0 estimate is %3.2f Hz.\n', 1/(t(I+15)));

[b0,a0]=butter(2,325/(Fs/2));
xin = abs(x);
xin=filter(b0,a0,xin);
xin = xin-mean(xin);
x2=zeros(length(xin),1);
x2(1:length(x)-1)=xin(2:length(x));
zc=length(find((xin>0 & x2<0) | (xin<0 & x2>0)));
F0=0.5*Fs*zc/length(x);
fprintf('Zero-crossing F0 estimate is %3.2f Hz.\n',F0);