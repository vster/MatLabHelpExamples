t = (0:0.001:1)';
y = sin(2*pi*50*t) + 2*sin(2*pi*120*t);
rng default;
yn = y + 0.5*randn(size(t));
plot(t(1:50),yn(1:50))