% Integration

syms a b theta x y n u z
f = x^n;
int(f)

f = y^(-1);
int(f)

f = n^x;
int(f)

f = sin(a*theta+b);
int(f)

f = 1/(1+u^2);
int(f)

f = exp(-x^2);
int(f)

% Definite Integral

f = x^7;
a = 0;
b = 1;
int(f, a, b)

f = 1/x;
a = 1;
b = 2;
int(f, a, b)

f = log(x)*sqrt(x);
a = 0;
b = 1;
int(f, a, b)

f = exp(-x^2);
a = 0;
b = inf;
int(f, a, b)

f = besselj(1,z)^2;
a = 0;
b = 1;
int(f, a, b)

syms z
a = int(besselj(1,z)^2,0,1)
a = double(a)

% Integration with Real Parameters
syms x
a = sym(1/2);
f = exp(-a*x^2);
ezplot(f)

syms a
assume(a > 0);
syms x
f = exp(-a*x^2);
int(f, x, -inf, inf)

% Integration with Complex Parameters
syms a x clear 
f = 1/(a^2 + x^2);
F = int(f, x, -inf, inf)
g = subs(F, 1 + i)
double(g)





