% fourier
syms x y
f = exp(-x^2);
fourier(f, x, y)

syms x t y
f = exp(-x^2)*exp(-t^2);
fourier(f, y)

fourier(f)

syms t w
fourier(t^3, t, w)

syms t0
fourier(heaviside(t - t0), t, w)

syms f(t) w
F = fourier(f, t, w)

ifourier(F, w, t)

syms x clear

syms f(t) w
fourier(diff(f(t), t), t, w)

syms a b c d w x y z
fourier([exp(x), 1; sin(y), i*z],[w, x; y, z],[a, b; c, d])

syms w x y z a b c d
fourier(x,[x, w; y, z],[a, b; c, d])

syms f1(x) f2(x) a b
f1(x) = exp(x);
f2(x) = x;
fourier([f1, f2],x,[a, b])





