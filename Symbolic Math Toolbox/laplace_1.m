% laplace

syms x y
f = 1/sqrt(x);
laplace(f, x, y)

syms a t y
f = exp(-a*t);
laplace(f, y)

laplace(f)

syms t s
laplace(dirac(t - 3), t, s)

laplace(heaviside(t - pi), t, s)

syms f(t) s
F = laplace(f, t, s)

ilaplace(F, s, t)

syms f(t) s
laplace(diff(f(t), t), t, s)

syms a b c d w x y z
laplace([exp(x), 1; sin(y), i*z],[w, x; y, z],[a, b; c, d])

syms w x y z a b c d
laplace(x,[x, w; y, z],[a, b; c, d])

syms f1(x) f2(x) a b
f1(x) = exp(x);
f2(x) = x;
laplace([f1, f2],x,[a, b])


