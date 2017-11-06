function y = OFDM_Packer92( u )
%UNTITLED Summary of this function goes here
%codegen
IndexU=[1:12,1+(13:36),2+(37:60),3+(61:84),4+(85:96),5+(97:108),6+(109:132),7+(133:156),8+(157:180),9+(181:192)]';
IndexP=1+[12,1+36,2+60,3+84,4+96,5+108,6+132,7+156,8+180]';
ValsP=complex(1,0)*[1;-1;1;-1;0;-1;-1;1;1];
LEN=numel(u)+numel(IndexP);
y=complex(0,0)*zeros(LEN,1);
y(IndexU)=u;
y(IndexP)=ValsP;
end

