options.Interpreter = 'tex';
% Include the desired Default answer
options.Default = 'Don''t know';
% Create a TeX string for the question
qstring = 'Is \Sigma(\alpha - \beta) < 0?';
choice = questdlg(qstring,'Boundary Condition',...
    'Yes','No','Don''t know',options)