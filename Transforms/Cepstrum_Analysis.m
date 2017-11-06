t = 0:0.01:1.27;
s1 = sin(2*pi*45*t);

s2 = s1 + 0.5*[zeros(1,20) s1(1:108)];

c = cceps(s2);
plot(t,c)

y = [4 1 5];                 % Non-minimum phase sequence
[xhat,yhat] = rceps(y);
xhat2= rceps(yhat); 
[xhat' xhat2']