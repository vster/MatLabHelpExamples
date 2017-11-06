load('pulseex.mat', 'x', 't');
fs = 4e6;
[w,initcross,finalcross] = pulsewidth(x,fs);
plot(t.*1e6,x);
set(gca,'xtick',[initcross*1e6 finalcross*1e6]);
grid on;
xlabel('microseconds');