% cond
% Condition number of matrix

A = inv(sym(magic(3)));
condN2 = cond(A)

vpa(condN2, 20)

A = inv(sym(magic(3)));
condN1 = cond(A, 1)
condNf = cond(A, 'fro')
condNi = cond(A, inf)

vpa(condN1, 20)
vpa(condNf, 20)
vpa(condNi, 20)

H = sym(hilb(3));
condN2 = vpa(cond(H), 30)
condN1 = vpa(cond(H, 1), 30)
condNf = vpa(cond(H, 'fro'), 30)
condNi = vpa(cond(H, inf), 30)


