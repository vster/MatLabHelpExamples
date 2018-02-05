% Solve an Algebraic Equation

syms a b c x
S = a*x^2 + b*x + c;
X1=solve(S)
pretty(X1)

b = solve(S, b)

syms x
s = solve(cos(2*x) + sin(x) == 1)