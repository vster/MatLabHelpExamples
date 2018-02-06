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

% simplifyFraction
syms x
f =(x^3 - 1)/(x - 1);
simplifyFraction(f)

f = (x^3 - x^2*y - x*y^2 + y^3)/(x^3 + y^3);
simplifyFraction(f)

f = (1 - exp(x)^4)/(1 + exp(x))^4;
simplifyFraction(f)

% simplify
syms x
f = (1 - x^2)/(1 - x);
simplify(f)

syms a
f = (1/a^3 + 6/a^2 + 12/a + 8)^(1/3);
simplify(f)

syms x y
f = exp(x) * exp(y);
simplify(f)

syms x
f = besselj(2, x) + besselj(0, x);
simplify(f)

syms x
f = gamma(x + 1) - x*gamma(x);
simplify(f)

syms x
f = cos(x)^2 + sin(x)^2;

















