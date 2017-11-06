x = -3:0.01:3;
rng default
y = 2*x+randn(size(x));
plot(x,y)

coeffs = polyfit(x,y,1);
yfit = coeffs(2)+coeffs(1)*x;
plot(x,y); hold on;
plot(x,yfit,'r','linewidth',2)

residuals = y-yfit;
[xc,lags] = xcorr(residuals,50,'coeff');

conf99 = sqrt(2)*erfcinv(2*.01/2)

lconf = -conf99/sqrt(length(x));
upconf = conf99/sqrt(length(x));

stem(lags,xc,'markerfacecolor',[0 0 1]);
set(gca,'ylim',[lconf-0.03 1.05]);
hold on;
line(lags,lconf*ones(size(lags)),'color','r','linewidth',2);
line(lags,upconf*ones(size(lags)),'color','r','linewidth',2);
title('Sample Autocorrelation with 99% Confidence Intervals');

Fs = 1000;
t = 0:1/Fs:1-1/Fs;
rng default
x = cos(2*pi*100*t)+randn(size(t));

xdft = fft(x);
ampest = 2/length(x)*xdft(101);
xfit = real(ampest)*cos(2*pi*100*t)+imag(ampest)*sin(2*pi*100*t);
plot(t,x,'r-.','linewidth',2); hold on;
plot(t,xfit,'b','linewidth',2);
axis([0 0.30 -4 4]);

residuals = x-xfit;
[xc,lags] = xcorr(residuals,50,'coeff');

stem(lags,xc,'markerfacecolor',[0 0 1]);
set(gca,'ylim',[lconf-0.03 1.05]);
hold on;
line(lags,lconf*ones(size(lags)),'color','r','linewidth',2);
line(lags,upconf*ones(size(lags)),'color','r','linewidth',2);
title('Sample Autocorrelation with 99% Confidence Intervals');

x = x+3/4*sin(2*pi*200*t);
xdft = fft(x);
ampest = 2/length(x)*xdft(101);
xfit = real(ampest)*cos(2*pi*100*t)+imag(ampest)*sin(2*pi*100*t);
residuals = x-xfit;
[xc,lags] = xcorr(residuals,50,'coeff');

stem(lags,xc,'markerfacecolor',[0 0 1]);
set(gca,'ylim',[lconf-0.12 1.05]);
hold on;
line(lags,lconf*ones(size(lags)),'color','r','linewidth',2);
line(lags,upconf*ones(size(lags)),'color','r','linewidth',2);
title('Sample Autocorrelation with 99% Confidence Intervals');