% int
% Indefinite Integral of a Univariate Expression
syms x
int(-2*x/(1 + x^2)^2)

% Indefinite Integrals of a Multivariate Expression
syms x z
int(x/(1 + z^2), x)
int(x/(1 + z^2), z)
symvar(x/(1 + z^2), 1)

% Definite Integrals of Univariate Expressions
syms x
int(x*log(1 + x), 0, 1)

syms x t
int(2*x, [sin(t), 1])

% Integrals of Matrix Elements
syms a x t z
int([exp(t), exp(a*t); sin(t), cos(t)])

% Apply IgnoreAnalyticConstraints
syms x
int(acos(sin(x)), x)

int(acos(sin(x)), x, 'IgnoreAnalyticConstraints', true)

% Find the Cauchy Principal Value
syms x
int(1/(x - 1), x, 0, 2)

int(1/(x - 1), x, 0, 2, 'PrincipalValue', true)

% Approximate Indefinite Integrals
syms x
F = sin(sinh(x));
int(F, x)

int(taylor(F, x, 'ExpansionPoint', 0, 'Order', 10), x)

% Approximate Definite Integrals
syms x
F = int(cos(x)/sqrt(1 + x^2), x, 0, 10)

vpa(F, 5)






