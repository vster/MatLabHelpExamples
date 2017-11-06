function y=OFDM_Equalizer92(u,P)
%#codegen
Index1=[1:2:99,103:2:201];
training=u(Index1,1);
Pilots=P(Index1);
Ch=training./Pilots;
gain=conj(Ch)./(Ch.*conj(Ch));
G=RepeatGains(gain);
%G=InterpolateGains(gain);
Index2=[1:100,102:201];
data=u(Index2,2);
y=G.*data;
end

function G=RepeatGains(gain)
%#codegen
G=complex(zeros(2*numel(gain),1));
G(1:2:200)=gain;
G(2:2:200)=gain;
end