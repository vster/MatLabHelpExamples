% Linear Algebraic Operations

H = hilb(3)

H = sym(H)

inv(H)

det(H)

% Solve Hx = b
b = [1; 1; 1];
x = H\b

digits(16);
V = vpa(hilb(3))

inv(V)

1/det(V)

V\b

null(H)

colspace(H)

syms s
H(1,1) = s
Z = det(H)
sol = solve(Z)

H = subs(H, s, sol)

det(H)

inv(H)

Z = null(H)
C = colspace(H)



