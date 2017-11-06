function DrawScatterPlot(h,ofdm_rec)
set(get(get(h, 'Children'), 'Children'), 'XData', ...
real(ofdm_rec), 'Ydata', imag(ofdm_rec));
pause(0.005); % Pause between re-draws
drawnow; % Refresh the image