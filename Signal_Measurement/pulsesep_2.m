load('pulseex.mat', 'x', 't');
[s,~,finalcross,nextcross,midlev] = pulsesep(x,t);
fprintf('Pulse separation is %2.3f microseconds \n',s*1e6);
plot(t.*1e6,x); hold on;
grid on; axis tight; xlabel('microseconds');
plot(finalcross.*1e6,midlev,'ro','markerfacecolor',[1 0 0]);
plot(nextcross.*1e6,midlev,'ro','markerfacecolor',[1 0 0]);