p = profile('info');
save myprofiledata p
clear p
load myprofiledata
profview(0,p)