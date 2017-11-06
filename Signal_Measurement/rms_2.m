t = 0:0.001:1-0.001;
x = cos(2*pi*100*t)';
X = repmat(x,1,4);
amp = 1:4;
amp = repmat(amp,1e3,1);
X = X.*amp;
Y = rms(X);