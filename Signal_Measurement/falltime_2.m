load('negtransitionex.mat','x','t');
plot(t,x);
F = falltime(x,'PercentReferenceLevels',[20 80]);