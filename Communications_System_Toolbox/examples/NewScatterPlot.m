function h=NewScatterPlot(Title)
%
h = scatterplot(0);
title(Title);
xlabel('In-Phase Amplitude'); % Set axis labels
ylabel('Quadrature Amplitude');
xlim([-2 2]); % Set axis limits
ylim([-2 2]);
grid on;