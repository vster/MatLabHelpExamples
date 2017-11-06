Fs = 1e3;
t = 0:0.001:1-0.001;
rng default;
x = 0.25*cos(2*pi*100*t)+randn(size(t));

[Pxx,F] = periodogram(x,rectwin(length(x)),length(x),Fs);
Pxx = Pxx(2:length(x)/2);

[maxval,index] = max(Pxx);
fisher_g = Pxx(index)/sum(Pxx);

F = F(2:end-1);
F(index)

N = length(Pxx);
    upper  = floor(1/fisher_g);
    for nn = 1:3
        I(nn) = ...
            (-1)^(nn-1)*nchoosek(N,nn)*(1-nn*fisher_g)^(N-1);
    end
pval = sum(I);