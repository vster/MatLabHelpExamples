t = 0:1/100:10-1/100;                     % Time vector
x = sin(2*pi*15*t) + sin(2*pi*40*t);      % Signal

y = fft(x);                               % Compute DFT of x
m = abs(y); p = unwrap(angle(y));         % Magnitude and phase

f = (0:length(y)-1)*100/length(y);        % Frequency vector
subplot(2,1,1)
plot(f,m), title Magnitude
set(gca,'XTick',[15 40 60 85])
subplot(2,1,2)
plot(f,p*180/pi), title Phase
set(gca,'XTick',[15 40 60 85])