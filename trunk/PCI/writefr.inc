// inc использует 3 параметра
// - номер фреймера
// - адрес регистра во фреймере
// - значение регистра
addr:=$6400+(numfr-1)*$100;
if ((regs && 1) =0) then tregs:=regs; mask:=$ff00; mult:=1;
                  else tregs:=regs-1; mask:=$00ff;mult:=256;
fi;

setmask($b);
sendmess(mod*256,$ff01,2,tregs,addr);
recvmess(a,b,c,d,e,temp,g);
//writeln(a,b,c,d,e,f,g);
valnew:=(temp && mask) || (val*mult);

setmask($d);
sendmess(mod*256,$ff01,2,tregs,addr,valnew); recvmess(a);
setmask($b);
sendmess(mod*256,$ff01,2,tregs,addr);
recvmess(a,b,c,d,e,f,g);
//writeln(a,b,c,d,e,f,g);
