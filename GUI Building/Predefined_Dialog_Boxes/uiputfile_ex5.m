[filename, pathname] = uiputfile('*.m',...
                       'Pick a MATLAB program file');
if isequal(filename,0) || isequal(pathname,0)
   disp('User selected Cancel')
else
   disp(['User selected ',fullfile(pathname,filename)])
end