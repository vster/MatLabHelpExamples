% Combine subs and double for Numeric Evaluations
syms t
M = (1 - t^2)*exp(-1/2*t^2);
P = (1 - t^2)*sech(t);

ezplot(M);
hold on;
ezplot(P);
hold off;

T = -6:0.05:6;
MT = double(subs(M, t, T));
PT = double(subs(P, t, T));
plot(T, MT, 'b', T, PT, 'r-.');
title(' ');
legend('M','P');
xlabel('t'); grid;