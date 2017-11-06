[filename, pathname] = uigetfile('*.m', 'Select a MATLAB code file');
if isequal(filename,0)
   disp('User selected Cancel')
else
   disp(['User selected ', fullfile(pathname, filename)])
end