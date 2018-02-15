% Taylor Series

syms x
f = 1/(5 + 4*cos(x));
T = taylor(f, 'Order', 8)

pretty(T)

syms x
g = exp(x*sin(x));
t = taylor(g, 'ExpansionPoint', 2, 'Order', 12);

% pretty(t)

size(char(t))

t = simplify(t);
size(char(t))

xd = 1:0.05:3; yd = subs(g,x,xd);
ezplot(t, [1, 3]); hold on;
plot(xd, yd, 'r-.')
title('Taylor approximation vs. actual function');
legend('Taylor','Function')


