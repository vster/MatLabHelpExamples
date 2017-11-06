load('pulseex.mat', 'x', 't');
[p,initcross,~,nextcross,midlev] = pulseperiod(x,t);
fprintf('Pulse period is %2.3f microseconds \n',p*1e6);
plot(t.*1e6,x); hold on;
grid on; axis tight; xlabel('microseconds');
plot(initcross.*1e6,midlev,'ro','markerfacecolor',[1 0 0]);
plot(nextcross.*1e6,midlev,'ro','markerfacecolor',[1 0 0]);