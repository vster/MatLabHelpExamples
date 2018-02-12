% hessian

syms x y z
f = x*y + 2*z*x;
hessian(f)

syms x y z
f = x*y + 2*z*x;
jacobian(gradient(f))