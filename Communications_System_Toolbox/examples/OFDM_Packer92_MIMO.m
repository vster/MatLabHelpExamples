function y = OFDM_Packer92_MIMO( u )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
tmp=reshape(u,numel(u)/2,2);
IndexU=[1:12,1+(13:36),2+(37:60),3+(61:84),4+(85:96),5+(97:108),6+(109:132),7+(133:156),8+(157:180),9+(181:192)]';
IndexP=1+[12,1+36,2+60,3+84,4+96,5+108,6+132,7+156,8+180]';
ValsP=[1;-1;1;-1;0;-1;-1;1;1]*[1+0j,1+0j];
LEN=size(tmp,1)+size(IndexP,1);
y=complex(0,0)*zeros(LEN,2);
y(IndexU,:)=tmp;
y(IndexP,:)=ValsP;
end