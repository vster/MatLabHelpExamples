prompt = {'Amplitude:','Frequency:'};
dlg_title = 'Square';
num_lines = 1;
def = {'1','1'};
params = inputdlg(prompt,dlg_title,num_lines,def);
a=str2double(params(1));
f=str2double(params(2));

t=linspace(-1,1,1000);
y=a*square(2*pi*f*t);
plot(t,y);
axis([-1 1 -1.2*a 1.2*a])
grid on;