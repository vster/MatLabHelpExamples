Fs = 44.1e3;
 t = 0:1/Fs:1;
 x = cos(2*pi*1000*t)+8e-4*sin(2*pi*2000*t)+2e-5*cos(2*pi*3000*t-pi/4)+...
     8e-6*sin(2*pi*4000*t);
 
 NumHarmonics = 6;
 [thd_db,harmpow,harmfreq] = thd(x,Fs,6);
 
 percent_thd = 100*(10^(thd_db/20))
 
 T = table(harmfreq,harmpow,'VariableNames',{'Frequency','Power'})