prompt = {'Amplitude:','Frequency:'};
dlg_title = 'Sinus';
num_lines = 1;
def = {'1','1'};
params = inputdlg(prompt,dlg_title,num_lines,def);
a=str2double(params(1));
f=str2double(params(2));

t=linspace(0,1,1000);
y=a*sin(2*pi*f*t);
plot(t,y);
grid on;

