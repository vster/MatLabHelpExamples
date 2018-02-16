% ilaplace
syms x y
F = 1/y^2;
ilaplace(F, y, x)

syms a s x
F = 1/(s - a)^2;
ilaplace(F, x)

ilaplace(F)

syms s t
ilaplace(1, s, t)

ilaplace(exp(-2*s)/(s^2 + 1) + s/(s^3 + 1), s, t)

syms F(s) t
f = ilaplace(F, s, t)

laplace(f, t, s)

syms a b c d w x y z
ilaplace([exp(x), 1; sin(y), i*z],[w, x; y, z],[a, b; c, d])

syms w x y z a b c d
ilaplace(x,[x, w; y, z],[a, b; c, d])

syms f1(x) f2(x) a b
f1(x) = exp(x);
f2(x) = x;
ilaplace([f1, f2],x,[a, b])




