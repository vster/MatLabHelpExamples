[z,p,k] = besselap(6);        % Lowpass filter prototype
[num,den] = zp2tf(z,p,k);     % Convert to transfer function form
freqs(num,den)                % Frequency response of analog filter
%fvtool(num,den)  