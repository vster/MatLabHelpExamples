load('transitionex.mat', 'x');
[S,SLEV,SINST] = settlingtime(x,10);
plot(x); hold on;
plot(SINST,SLEV,'ro','markerfacecolor',[1 0 0]);