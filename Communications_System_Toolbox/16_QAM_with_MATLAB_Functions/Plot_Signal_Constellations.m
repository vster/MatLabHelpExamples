%% Binary Symbol Mapping for 16-QAM Constellation
% Apply 16-QAM modulation to all possible input values using the default symbol mapping, binary.

M = 16;                         % Modulation order
x = (0:15)';                    % Integer input
y1 = qammod(x, 16, 0);          % 16-QAM output, phase offset = 0

% Use the scatterplot function to plot the constellation diagram and annotate 
% it with binary representations of the constellation points.

scatterplot(y1)
text(real(y1)+0.1, imag(y1), dec2bin(x))
title('16-QAM, Binary Symbol Mapping')
axis([-4 4 -4 4])

%% Gray-coded Symbol Mapping for 16-QAM Constellation
% Apply 16-QAM modulation to all possible input values using Gray-coded symbol mapping.

y2 = qammod(x, 16, 0, 'gray');  % 16-QAM output, phase offset = 0, Gray-coded

% Use the scatterplot function to plot the constellation diagram and 
% annotate it with binary representations of the constellation points.

scatterplot(y2)
text(real(y2)+0.1, imag(y2), dec2bin(x))
title('16-QAM, Gray-coded Symbol Mapping')
axis([-4 4 -4 4])