t = 0:0.001:1-0.001;
x = cos(2*pi*100*t);
X = repmat(x,4,1);
amp = (1:4)';
amp = repmat(amp,1,1e3);
X = X.*amp;
Y = rssq(X,2);