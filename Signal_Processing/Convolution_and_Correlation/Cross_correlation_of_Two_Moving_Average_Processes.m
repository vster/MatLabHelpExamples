rng default;
w = randn(100,1);
x = filter([1 1],1,w);
y = filter([1 -1],1,w);

[xc,lags] = xcorr(x,y,20,'biased');
stem(lags,xc,'markerfacecolor',[0 0 1]);
Xc = zeros(size(xc));
Xc(20) = -1;
Xc(22) = 1;
hold on;
stem(lags,Xc,'color',[1 0 0],'marker','none','linewidth',2);
q = legend('Sample Cross-correlation', ...
           'Theoretical Cross-correlation', ...
           'Location','NorthWest');
set(q,'FontSize',9,'Box','off')