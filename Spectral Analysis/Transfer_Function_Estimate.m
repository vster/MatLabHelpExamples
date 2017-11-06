h = ones(1,10)/10;	            % Moving-average filter
yn = filter(h,1,xn);
[HEST,f] = tfestimate(xn,yn,256,128,256,fs);
H = freqz(h,1,f,fs);
subplot(2,1,1); plot(f,abs(H)); 
title('Actual Transfer Function Magnitude'); 
subplot(2,1,2); plot(f,abs(HEST));
title('Transfer Function Magnitude Estimate'); 
xlabel('Frequency (Hz)');

mscohere(xn,yn,256,128,256,fs)