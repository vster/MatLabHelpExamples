[filename, pathname] = uigetfile( ...
{'*.m;*.fig;*.mat;*.slx;*.mdl',...
 'MATLAB Files (*.m,*.fig,*.mat,*.slx,*.mdl)';
   '*.m',  'Code files (*.m)'; ...
   '*.fig','Figures (*.fig)'; ...
   '*.mat','MAT-files (*.mat)'; ...
   '*.mdl;*.slx','Models (*.slx, *.mdl)'; ...
   '*.*',  'All Files (*.*)'}, ...
   'Pick a file');