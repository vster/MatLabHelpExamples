rng default;
x = randn(1e3,1);
[xc,lags] = xcorr(x,20,'coeff');

lconf = -1.96/sqrt(length(x));
upconf = 1.96/sqrt(length(x));

stem(lags,xc,'markerfacecolor',[0 0 1]);
set(gca,'ylim',[lconf-0.03 1.05]);
hold on;
line(lags,lconf*ones(size(lags)),'color','r','linewidth',2);
line(lags,upconf*ones(size(lags)),'color','r','linewidth',2);
title('Sample Autocorrelation with 95% Confidence Intervals');