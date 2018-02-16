% iztrans
syms k x
F =  2*x/(x - 2)^2;
iztrans(F, x, k)

syms z a k
F = exp(a/z);
iztrans(F, k)

iztrans(F)

syms n z
iztrans(1/z, z, n)

iztrans((z^3 + 3*z^2 + 6*z + 5)/z^5, z, n)

syms F(z) n
f = iztrans(F, z, n)

ztrans(f, n, z)

syms a b c d w x y z
iztrans([exp(x), 1; sin(y), i*z],[w, x; y, z],[a, b; c, d])

syms w x y z a b c d
iztrans(x,[x, w; y, z],[a, b; c, d])

syms f1(x) f2(x) a b
f1(x) = exp(x);
f2(x) = x;
iztrans([f1, f2],x,[a, b])

