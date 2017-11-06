t = (-1:0.01:1)';
 x = sin(4*pi*t); 
 hanlytc = dsp.AnalyticSignal(200); 
 y = step(hanlytc,x);

 subplot(2,1,1), plot(t, x); 
 title('Original Signal');
 subplot(2,1,2), plot(t, [real(y) imag(y)]); 
 title('Analytic signal of the input')
 legend('Real signal','Imaginary signal',...
    'Location','best');