% potential
% Potential of vector field

syms x y z
P = potential([x, y, z*exp(z)], [x y z])
simplify(gradient(P, [x y z]))

syms x y z
P = potential([x, y, z*exp(z)], [x y z], [0 0 0])

subs(P, [x y z], [0 0 0])

potential([x*y, y], [x y])