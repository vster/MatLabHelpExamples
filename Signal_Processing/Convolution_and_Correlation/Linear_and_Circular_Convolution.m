x = [2 1 2 1];
y = [1 2 3];
clin = conv(x,y);

xpad = [x zeros(1,6-length(x))];
ypad = [y zeros(1,6-length(y))];
ccirc = ifft(fft(xpad).*fft(ypad));

subplot(211)
stem(clin,'markerfacecolor',[0 0 1]);
title('Linear Convolution of x and y');
set(gca,'ylim',[0 11]);
subplot(212)
stem(ccirc,'markerfacecolor',[0 0 1]);
set(gca,'ylim',[0 11]);
title('Circular Convolution of xpad and ypad');

N = length(x)+length(y)-1;
xpad = [x zeros(1,12-length(x))];
ypad = [y zeros(1,12-length(y))];
ccirc = ifft(fft(xpad).*fft(ypad));
ccirc = ccirc(1:N);

ccirc2 = cconv(x,y,6);