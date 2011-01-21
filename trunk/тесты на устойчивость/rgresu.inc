
writeln('модуль --------------------', Mod);

start := AtSeg ;

setmask($b);SendMess(Mod*256,$ff01,2,0,start);
if recvmess(a,b,c,d,e,a1)>0 then
if a1 = $1234 then // версия новая
len := $18 ;
again_new:
include gdump.inc;

start := start+len/8 +1;
rg_again:
setmask($b);SendMess(Mod*256,$ff01,4,$c,start-1);
 if recvmess(a,b,c,d,e,a1,a2)>0 then
   if e<> start-1 then goto rg_again fi ;
   if a1 = 0 then goto fin fi ;
 else goto rg_again fi ;
len := a2 ;

writeln('**** death trace from ', a1,'-----',len*2); 
goto again_new;

else // версия старая
len := a2 ;len := Len1 ; writeln('---- death trace from ', START1,'-----');
include gdump.inc;
start := start+len/8 +1 ; len := Len2 ;writeln('---- death trace from ', START2,'-----');
include gdump.inc;
start := start+len/8 +1 ; len := Len3 ;writeln('---- death trace from ', START3,'-----');
include gdump.inc;
start := start+len/8 +1 ; len := Len4 ;writeln('---- death trace from ', START4,'-----');
include gdump.inc;
start := start+len/8 +1 ; len := Len5 ;writeln('---- death trace from ', START5,'-----');
include gdump.inc;
start := start+len/8 +1 ; len := Len6 ;writeln('---- death trace from ', START6,'-----');
include gdump.inc;
start := start+len/8 +1 ; len := Len7 ;writeln('---- death trace from ', START7,'-----');
include gdump.inc;
start := start+len/8 +1 ; len := Len8 ;writeln('---- death trace from ', START8,'-----');
include gdump.inc;
start := start+len/8 +1 ; len := Len9 ;writeln('---- death trace from ', START9,'-----');
include gdump.inc;
fi ;
fi ;