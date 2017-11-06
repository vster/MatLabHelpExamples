load('transitionex.mat', 'x');
y = [x; fliplr(x)];
fs = 4e6;
t = 0:1/fs:(length(y)*1/fs)-1/fs;
[S,SLEV,SINST] = settlingtime(y,fs,1e-6);
% equivalent to [S,SLEV,SINST] = settlingtime(y,t);
plot(t,y); hold on;
plot(SINST,SLEV,'ro','markerfacecolor',[1 0 0]);
legend('Bilevel Waveform','Settling Points','Location','SouthWest');