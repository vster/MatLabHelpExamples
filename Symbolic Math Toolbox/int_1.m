% int
% Indefinite Integral of a Univariate Expression
syms x
int(-2*x/(1 + x^2)^2)

% Indefinite Integrals of a Multivariate Expression
syms x z
int(x/(1 + z^2), x)
int(x/(1 + z^2), z)
