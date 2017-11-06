t = 0:0.001:1-0.001;
x = cos(2*pi*100*t)+randn(size(t));
p = bandpower(x)
norm(x,2)^2/numel(x)