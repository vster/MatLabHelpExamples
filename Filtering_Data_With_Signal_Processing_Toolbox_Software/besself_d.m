Fs = 100;                           % Sampling Frequency
[z,p,k] = besself(5,1000);          % Bessel analog filter design
[zd,pd,kd] = bilinear(z,p,k,Fs);    % Analog to digital mapping
sos = zp2sos(zd,pd,kd);             % Convert to SOS form
fvtool(sos)                         % Visualize the digital filter