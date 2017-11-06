xe = ecg(512);			% Single ecg wave
xr = repmat(xe,1,8);	% Replicate it to create more data
x = xr + 0.1.*randn(1,length(xr));  % Add noise

% Fast Walsh-Hadamard transform. Use default values
% for the number of points to use for the transform and
% for the ordering - sequency -- why???

y = fwht(x);
figure('color','white');
subplot(2,1,1);
plot(x);							% Plot original noisy signal
xlabel('Sample index');
ylabel('Amplitude');
title('ECG Signal');
subplot(2,1,2);
plot(abs(y))						% Plot magnitude of transformed signal
xlabel('Sequency index');
ylabel('Magnitude');
title('WHT Coefficients');