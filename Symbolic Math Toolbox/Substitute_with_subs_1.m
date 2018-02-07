% Substitute with subs
syms a b c
A = [a b c; b c a; c a b];
[v,E] = eig(A)

syms S
v = subs(v,(a^2 - a*b - a*c + b^2 - b*c + c^2)^(1/2), S)
E = subs(E,(a^2 - a*b - a*c + b^2 - b*c + c^2)^(1/2), S)

v = simplify(v)

S

S = (a^2 - a*b - a*c + b^2 - b*c + c^2)^(1/2);

subs(S, {a, b, c}, {1, 2, 3})

subs(subs(v), {a, b, c}, {1, 2, 3})

[a, b, c]

S
v

S = subs(S, {a, b, c}, {1, 2, 3})
v = subs(subs(v), {a, b, c}, {1, 2, 3})

a = 1; b = 2; c = 3;
[a, b, c]

S = subs(S)
v = subs(v)
