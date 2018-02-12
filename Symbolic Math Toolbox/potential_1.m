% potential
syms x y z
P = potential([x, y, z*exp(z)], [x y z])
simplify(gradient(P, [x y z]))

syms x y z
P = potential([x, y, z*exp(z)], [x y z], [0 0 0])
