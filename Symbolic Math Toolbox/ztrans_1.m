% ztrans

syms k x
f = sin(k);
ztrans(f, k, x)

syms a n x
f = a^n;
ztrans(f, x)

ztrans(f)

syms n z
ztrans(heaviside(n - 3), n, z)

ztrans(nchoosek(n, 2)*heaviside(5 - n), n, z)

syms f(n) z
F = ztrans(f, n, z)

iztrans(F, z, n)

syms a b c d w x y z
ztrans([exp(x), 1; sin(y), i*z],[w, x; y, z],[a, b; c, d])

syms w x y z a b c d
ztrans(x,[x, w; y, z],[a, b; c, d])

syms f1(x) f2(x) a b
f1(x) = exp(x);
f2(x) = x;
ztrans([f1, f2],x,[a, b])


