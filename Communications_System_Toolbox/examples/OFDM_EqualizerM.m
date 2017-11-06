function [y,y0,y1]=OFDM_EqualizerM(u,P0,P1)
%#codegen
Index0=[1:2:99,103:2:201];
Index1=(2:2:201);
IndexU=[1:100,102:201];
Pilots0=P0(Index0,1);
Pilots1=P1(Index1,1);
training0=u(Index0,1);
training1=u(Index1,1);
y=u(IndexU,2:3);
y0=RepeatGains(training0,Pilots0);
y1=RepeatGains(training1,Pilots1);
end

function G=RepeatGains(training,Pilots)
%#codegen
[Row,Col]=size(training);
Ch=training./Pilots;
gain=[Ch,Ch];
G=complex(zeros(2*Row,2*Col));
G(1:2:2*Row,:)=gain;
G(2:2:2*Row,:)=gain;
end