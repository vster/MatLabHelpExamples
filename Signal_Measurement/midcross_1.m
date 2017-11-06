load('transitionex.mat', 'x');
C = midcross(x);
plot(x); hold on;
plot([C C],[-0.5 2.5],'r','linewidth',2);