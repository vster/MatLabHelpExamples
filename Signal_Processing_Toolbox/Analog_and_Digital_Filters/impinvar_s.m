[b,a] = butter(4,0.3,'s');
[bz,az] = impinvar(b,a,100);
[sos,g] = tf2sos(bz,az);
fvtool(sos)