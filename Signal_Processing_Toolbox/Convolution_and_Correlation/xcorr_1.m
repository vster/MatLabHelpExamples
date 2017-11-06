x = 0:0.01:100;
X = sin(x);
noise=2*rand(1,length(X))-1;
X=X+noise;
[r,lags] = xcorr(X,'coeff');
max(r)
plot(lags,r)