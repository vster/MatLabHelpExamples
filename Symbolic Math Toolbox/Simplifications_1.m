% Simplifications
syms x
f = x^3 - 6*x^2 + 11*x - 6;
g = (x - 1)*(x - 2)*(x - 3);
h = -6 + (11 + (-6 + x)*x)*x;

pretty(f)
pretty(g)
pretty(h)

% collect
f = (x-1)*(x-2)*(x-3);
collect(f)

f = x*(x*(x - 6) + 11) - 6;
collect(f)

syms x t
f = (1+x)*t + x*t;
collect(f)

% expand
syms a b x y
f = a*(x + y);
expand(f)