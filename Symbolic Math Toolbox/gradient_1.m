% gradient
% Gradient vector of scalar function

syms x y z
f = 2*y*z*sin(x) + 3*x*sin(z)*cos(y);
gradient(f, [x, y, z])

syms x y
f = -(sin(x) + sin(y))^2;
g = gradient(f, [x, y])

[X, Y] = meshgrid(-1:.1:1,-1:.1:1);
G1 = subs(g(1), [x y], {X,Y}); G2 = subs(g(2), [x y], {X,Y});
quiver(X, Y, G1, G2)