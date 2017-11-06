h = 1/3*ones(3,1);
rng default
x = randn(1000,1);
y = filter(h,1,x);

[xc,lags] = xcorr(y,20,'biased');
stem(lags,xc,'markerfacecolor',[0 0 1])
Xc = zeros(size(xc));
Xc(19:23) = [1 2 3 2 1]/9*var(x);
hold on
stem(lags,Xc,'color',[1 0 0],'marker','none','linewidth',2)
legend('Sample autocorrelation','Theoretical autocorrelation', ...
    'Location','NorthEast'), legend boxoff
hold off

[pxx,wx] = pwelch(x);
[pyy,wy] = pwelch(y);
plot(wx/pi,20*log10(pxx),wy/pi,20*log10(pyy))
legend('Original sequence','Filtered sequence', ...
    'Location','SouthWest'), grid
xlabel 'Normalized Frequency (\times\pi rad/sample)'
ylabel 'Power/frequency (dB/rad/sample)'
title 'Welch Power Spectral Density Estimate'