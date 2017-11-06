rng default;
x = triang(20);
y = [zeros(3,1); x]+0.3*randn(length(x)+3,1);
subplot(211)
stem(x,'markerfacecolor',[0 0 1]); axis([0 22 -1 2]);
subplot(212)
stem(y,'markerfacecolor',[0 0 1]); axis([0 22 -1 2]);

[xc,lags] = xcorr(y,x);
[~,I] = max(abs(xc));
fprintf('Maximum cross correlation sequence value occurs at lag %d\n',lags(I));
figure;
stem(lags,xc,'markerfacecolor',[0 0 1]);