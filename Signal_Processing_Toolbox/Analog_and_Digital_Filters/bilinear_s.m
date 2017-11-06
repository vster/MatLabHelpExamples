Fs = 0.5;                             % Sampling frequency
[z,p,k] = ellipap(6,5,90);            % Lowpass filter prototype
[num,den] = zp2tf(z,p,k);             % Convert to transfer function form
[numd,dend] = bilinear(num,den,Fs);   % Analog to digital conversion
fvtool(numd,dend)                     % Visualize the filter