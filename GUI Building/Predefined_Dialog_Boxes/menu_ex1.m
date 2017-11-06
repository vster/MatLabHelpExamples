choice = menu('Choose a color','Red','Blue','Green');

t = 0:.1:60;
s = sin(t);
color = ['r','b','g']
plot(t,s,color(choice))