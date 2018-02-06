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

f = (x - 1)*(x - 2)*(x - 3);
expand(f)

f = x*(x*(x - 6) + 11) - 6;
expand(f)

f = exp(a + b);
expand(f)

f = cos(x + y);
expand(f)

f = cos(3*acos(x));
expand(f)

f = 3*x*(x^2 - 1) + x^3;
expand(f)

% horner
syms x
f = x^3 - 6*x^2 + 11*x - 6;
horner(f)

f = 1.1 + 2.2*x + 3.3*x^2;
horner(f)

% factor
syms x
f = x^3 - 6*x^2 + 11*x - 6;
factor(f)

f = x^3 - 6*x^2 + 11*x - 5;
factor(f)

f = x^6 + 1;
factor(f)

syms x
n = (1:9)';    
p = x.^n + 1;
f = factor(p);
[p, f]

N = sym(1);
for k = 2:11
   N(k) = 10*N(k-1)+1;
end
[N' factor(N')]


























