

writeln('DELIC ', delic);
sendmess($30fe, 4000, delic);

addr:=$fd10;      //fd10;

for p from 0 to 19 do

writeln;
if (p && 1) = 0 then writeln fi;

write(addr, ': ');

for k from 1 to 4 do

sendmess(modto,1070,addr);
recvmess(t0,t1, a0,a1,a2,a3);

if (a0&& $ff00) = 0 then write( ' ', a0) else  write(a0) fi;
if (a1&& $ff00) = 0 then write( ' ', a1) else  write(a1) fi;  write(' ');
if (a2&& $ff00) = 0 then write( ' ', a2) else  write(a2) fi;
if (a3&& $ff00) = 0 then write( ' ', a3) else  write(a3) fi;  write(' ');

addr:=addr+4;

od;
od;

writeln;
writeln;
