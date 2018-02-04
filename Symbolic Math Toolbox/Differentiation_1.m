% Differentiation

syms x
f = sin(5*x);
diff(f)

g = exp(x)*cos(x);
diff(g)
diff(g,2)
diff(diff(g))

c = sym('5');
diff(c)
diff(5)

% Derivatives of Expressions with Several Variables
syms s t
f = sin(s*t);
diff(f,t)
diff(f,s)
symvar(f, 1)
diff(f, t, 2)

% More Examples
syms a b x n t theta
syms x n
f = x^n;
diff(f)

syms a b t
f = sin(a*t + b);
diff(f)

syms theta
f = exp(i*theta);
diff(f)

syms nu z
b = besselj(nu,z);
db = diff(b)

syms a x
A = [cos(a*x),sin(a*x);-sin(a*x),cos(a*x)]
diff(A)

syms r l f
x = r*cos(l)*cos(f); y = r*cos(l)*sin(f); z = r*sin(l);
J = jacobian([x; y; z], [r l f])

detJ = simplify(det(J))

