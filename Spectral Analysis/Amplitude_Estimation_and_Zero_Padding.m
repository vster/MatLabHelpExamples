Fs = 1e4;
t = 0:0.001:1-0.001;
x = cos(2*pi*100*t)+sin(2*pi*202.5*t);

freqres = Fs/length(x);
xdft = fft(x);
xdft = xdft(1:length(x)/2+1);
xdft = 1/length(x).*xdft;
xdft(2:end-1) = 2*xdft(2:end-1);
freq = 0:Fs/length(x):Fs/2;
plot(freq,abs(xdft));
xlabel('Hz'); ylabel('Amplitude');
h = line(freq,ones(length(x)/2+1,1));
set(h,'color',[1 0 0],'linewidth',2);

xdft = fft(x,2000);
xdft = xdft(1:length(xdft)/2+1);
xdft = 1/length(x).*xdft;
xdft(2:end-1) = 2*xdft(2:end-1);
freq = 0:Fs/(2*length(x)):Fs/2;
plot(freq,abs(xdft));
xlabel('Hz'); ylabel('Amplitude');
h = line(freq,ones(2*length(x)/2+1,1));
set(h,'color',[1 0 0],'linewidth',2);