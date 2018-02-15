% Compute Fourier and Inverse Fourier Transforms
syms x
cauchy = 1/(pi*(1+x^2));
fcauchy = fourier(cauchy)

fcauchy = expand(fcauchy)

ezplot(fcauchy)

finvfcauchy = ifourier(fcauchy)

simplify(finvfcauchy)

syms w y(x)
fourier(diff(y(x), x, 4), x, w)

G = 1/(w^4 + 1024);
g = ifourier(G, w, x);
g = simplify(g);
pretty(g)

XX = -3:0.05:3;
YY = double(subs(g, x, XX));
plot(XX, YY)
title('Beam Deflection for a Point Shock')
xlabel('x'); ylabel('y(x)');
