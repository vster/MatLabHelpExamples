t = 0:99;
rng default;
x = cos(2*pi*1/10*t);
y = cos(2*pi*1/10*t-pi)+0.25*randn(size(t));

[xc,lags] = xcorr(y,x,20,'coeff');
stem(lags(21:end),xc(21:end),'markerfacecolor',[0 0 1]);
set(gca,'xtick',0:5:20);
hold on;
plot([5 5],[-1 1],'r','linewidth',2);