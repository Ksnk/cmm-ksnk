sendmess($30fe, 4000, delic);
addr:=$e000;
j := 0 ;
for s from 1 to 99999 do
if j>62 then writeln('.', S); j := 0 
else j := j+1;write('.'); fi ;
//delay(10);
//writeln('     сканируем делик', delic, 'по адресу', addr);
sendmess(modto,1070,addr);
if recvmess(t0,t1, a0,a1,a2,a3)>0 then 
if (a0<>$ea80) {|| (a1<>$eb80) } then

SetMask ($D);
SendMess ($3000,$ff01, 2, 14, $3200, $AAAA );
RecvMess (b1,b2,b3,b4,b5, dump1);
writeln('!');
write('найдено несоответствие!!!           ');
write(addr, ':'); write(a0); write(a1, ':'); write(a2); writeln(a3);
writeln;
write(s, 'попытка');
   goto exit;
    fi;
fi ;
//     addr:=addr+0;
      od;
exit:
