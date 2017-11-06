function y = OFDM_Unpacker92_MIMO(u)
%#codegen
x = u([1:12, 14:37, 39:62, 64:87, 89:112, 114:137, 139:162, 164:187, 189:200],:);
y=x(:);