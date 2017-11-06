% Set the sampling frequency, create the window, and obtain the discrete 
% Fourier transform of the window with 0 frequency in the center of the spectrum.

Fs = 10000;
win = hann(1000);
windft = fftshift(fft(win));

% Obtain the equivalent (rectangular) noise bandwidth of the Von Hann window.

bw = enbw(hann(1000),Fs);

% Plot the squared-magnitude DFT of the window and use the equivalent noise 
% bandwidth to overlay the equivalent rectangle.

freq = -(Fs/2):Fs/length(win):Fs/2-(Fs/length(win));
plot(freq,20*log10(abs(windft))); xlabel('Hz'); ylabel('dB');
axis([-60 60 -40 60])
maxgain = 20*log10(abs(windft(length(win)/2+1)));
hold on;
plot([-bw -bw],[-40 maxgain],'r--',...
    [bw bw],[-40 maxgain],'r--','linewidth',2);
plot([-bw bw],[maxgain maxgain],'r--','linewidth',2);