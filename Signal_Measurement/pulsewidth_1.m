load('pulseex.mat', 'x', 't');
w = pulsewidth(x, t);
plot(t,x); grid on;