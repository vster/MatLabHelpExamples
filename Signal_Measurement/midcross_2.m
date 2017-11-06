load('transitionex.mat','x','t');
Fs = 1/(t(2)-t(1));
C = midcross(x,Fs);