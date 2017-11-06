load('clockex.mat','x','t')
stem(t,x,'markerfacecolor',[0 0 1]); xlabel('Seconds'); ylabel('Volts');

levels = statelevels(x)

lowtol = [levels(1)-3/100*(levels(2)-levels(1)) ...
    levels(1)+3/100*(levels(2)-levels(1))];

hightol = [levels(2)-3/100*(levels(2)-levels(1)) ...
    levels(2)+3/100*(levels(2)-levels(1))];

y = zeros(size(x));
y(x>= lowtol(1) & x<= lowtol(2)) = 0;
y(x>= hightol(1) & x<= hightol(2)) = 1;
subplot(211)
stem(t,x,'markerfacecolor',[0 0 1]); ylabel('Volts');
subplot(212)
stem(t,y,'markerfacecolor',[0 0 1]); ylabel('{0,1}'); xlabel('Seconds');
set(gca,'ytick',[0 1])

