% Compute Laplace and Inverse Laplace Transforms
clear E
syms R1 R2 R3 L C real;
syms I1(t) Q(t) s;
dI1(t) = diff(I1(t), t);
dQ(t) = diff(Q(t),t);
E(t) = sin(t);  % Voltage
eq1(t) = dI1(t) + R2*dQ(t)/L - (R2 - R1)*I1(t)/L;
eq2(t) = dQ(t) - (E(t) - Q/C)/(R2 + R3) - R2*I1(t)/(R2 + R3);

L1(t) = laplace(eq1,t,s)
L2(t) = laplace(eq2,t,s)

syms LI1 LQ
NI1 = subs(L1(t),{R1,R2,R3,L,C,I1(0),Q(0)}, ...
      {4,2,3,1.6,1/4,15,2})
  
NQ = subs(L2,{R1,R2,R3,L,C,I1(0),Q(0)},{4,2,3,1.6,1/4,15,2})

NI1 =...
 subs(NI1,{laplace(I1(t),t,s),laplace(Q(t),t,s)},{LI1,LQ})

NI1 = collect(NI1,LI1)

NQ = ...
subs(NQ,{laplace(I1(t),t,s), laplace(Q(t),t,s)}, {LI1,LQ})

NQ = collect(NQ,LQ)

[LI1, LQ] = solve(NI1, NQ, LI1, LQ)

I1 = ilaplace(LI1, s, t)
Q = ilaplace(LQ, s, t)

subplot(2,2,1); ezplot(I1,[0,10]);
title('Current'); ylabel('I1(t)'); grid
subplot(2,2,2); ezplot(Q,[0,10]);
title('Charge'); ylabel('Q(t)'); grid
subplot(2,2,3); ezplot(I1,[5,25]);
title('Current'); ylabel('I1(t)'); grid
text(7,0.25,'Transient'); text(16,0.125,'Steady State');
subplot(2,2,4); ezplot(Q,[5,25]);
title('Charge'); ylabel('Q(t)'); grid
text(7,0.25,'Transient'); text(15,0.16,'Steady State');


