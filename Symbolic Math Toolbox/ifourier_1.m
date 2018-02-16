% ifourier
syms x y
F = sqrt(sym(pi))*exp(-y^2/4);
ifourier(F, y, x)

syms a w t real
F = exp(-w^2/(4*a^2));
ifourier(F, t)

ifourier(F)

syms a w t clear

syms t w
ifourier(dirac(w), w, t)

ifourier(2*exp(-abs(w)) - 1, w, t)

ifourier(1/(w^2 + 1), w, t)

syms F(w) t
f = ifourier(F, w, t)

syms a b c d w x y z
ifourier([exp(x), 1; sin(y), i*z],[w, x; y, z],[a, b; c, d])

syms w x y z a b c d
ifourier(x,[x, w; y, z],[a, b; c, d])

syms f1(x) f2(x) a b
f1(x) = exp(x);
f2(x) = x;
ifourier([f1, f2],x,[a, b])


