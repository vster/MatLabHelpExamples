% symprod
% Evaluate the Product of a Series
syms k
symprod(k)
symprod((2*k - 1)/k^2)

% Evaluate the Product of a Series Specifying Bounds
syms k
symprod(1 - 1/k^2, k, 2, Inf)
symprod(k^2/(k^2 - 1), k, 2, Inf)

syms k
symprod(1 - 1/k^2, k, [2, Inf])
symprod(k^2/(k^2 - 1), k, [2; Inf])

% Evaluate the Product of a Series Specifying the Product Index and Bounds
syms k x
symprod(exp(k*x)/x, k, 1, 10000)