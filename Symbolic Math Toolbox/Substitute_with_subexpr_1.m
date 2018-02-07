% Substitute with subexpr
syms a x
s = solve(x^3 + a*x + 1)

r = subexpr(s)

sigma

r1 = subexpr(s,'u')