% PLOTRESULTSMSKSIGNALRECOVERY Plot the signal constellation before and
% after synchronization as well as the timing, frequency and phase
% estimates. This script is used in commMSKSignalRecovery.m.

%   Copyright 2010 The MathWorks, Inc.
%   $Revision: 1.1.8.1 $ $Date: 2013/12/27 02:23:09 $


%%  
% Save the timing, carrier frequency, and phase estimates for plotting
timEstHist(p) = timEst;
freqShiftEstHist(p) = freqShiftEst;
phEstHist(p) = phEst;

%% Signal Constellation plots
% Prepare the scatter plots to display the signal constellation before and
% after synchronization
if ~exist('hfig_scatter', 'var')
  % Create the scatter plot to display the channel impaired signal
  % constellation
  hfig_scatter(1) = scatterplot(plot_rx, samplesPerSymbol);
  set(gcf,'units', 'normalized', 'position', [0 .5 .2 .3]);
  title('Received Signal'); 
  % Create the scatter plot to display the timing and carrier frequency
  % synchronized signal constellation
  hfig_scatter(2) = scatterplot(plot_rxFreqSync);
  set(gcf,'units', 'normalized', 'position', [.21 .5 .2 .3]);
  title('After Frequency Recovery');
  % Create the scatter plot to display the phase synchronized signal
  % constellation
  hfig_scatter(3) = scatterplot(plot_rxPhSync);
  set(gcf,'units', 'normalized', 'position', [.42 .5 .2 .3]);
  title('After Phase Recovery');
  
  % Get the line handles of the scatter plots in order to be able to update
  % the figure with new data
  hAxes = findobj( hfig_scatter , 'Type' , 'Axes' );
  hline = findobj( hAxes , 'Type' , 'Line' );
end

% Update the channel impaired signal constellation plot with data from the
% current frame
set(hline(1),'XData',real(plot_rx));
set(hline(1),'YData',imag(plot_rx));
% Update the timing and carrier frequency synchronized signal constellation
% plot with data from the current frame
set(hline(2),'XData',real(plot_rxFreqSync));
set(hline(2),'YData',imag(plot_rxFreqSync));
% Update the phase synchronized signal constellation plot with data from the
% current frame
set(hline(3),'XData',real(plot_rxPhSync));
set(hline(3),'YData',imag(plot_rxPhSync));

% Force figure update to view the results while the simulation is running
drawnow;

%% Channel impairment estimates 
% Plot timing, carrier frequency shift and phase estimate at the end of the
% simulation
if p==numFrames
  % Calculate the simulation time corresponding to each estimate
  tvec = (1:numFrames)*Ts*samplesPerFrame;
  figure;
  % Plot the timing estimate history
  subplot(3,1,1);
  plot(tvec,timEstHist);
  ylabel('Symbols');
  title('Timing Phase Estimate');
  % Plot the carrier frequency shift estimate history
  subplot(3,1,2);
  plot(tvec,freqShiftEstHist);
  ylabel('Hz'); ylim([40 55]);
  title('Frequency Estimate');
  % Plot the phase estimate history
  subplot(3,1,3);
  plot(tvec,phEstHist);
  xlabel('simulation time (s)'); ylabel('degrees');
  title('Phase Estimate');
end
