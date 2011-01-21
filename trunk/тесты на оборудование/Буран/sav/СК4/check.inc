//mod := 01 ;chan :=25;Err :=4; disp :=14451;

if disp > $8000 then // MTP chan
  setmask($b);sendmess(Mod*256,$FF01,12,disp-$8000,$1b0);
  if recvmess(a,b,c,d,e,Alive,DPC,SLS,nMessRecv,nMessSent)>0 then
    if Show=1 then write('||', chan); fi ;
    if Alive=0 then write('+') else write('-') fi ;
    if Show=1 then write(nMessRecv-MessRecv,nMessSent-MessSent); fi ;
    MessRecv:=nMessRecv;   MessSent:=nMessSent;
  else write('-');
  fi ;
else
if disp <> 0 then
  setmask($b);sendmess(Mod*256,$FF01,12,disp,$1b0);
  if recvmess(a,b,c,d,e,Alive,nMessRecv,f,niobCRC,nMessSent,niobErr)>0 then
    if Show=1 then write('||', chan); fi ;
    if Alive<>0 then write('+') else write('-') fi ;
  if Show=1 then 
    if (nMessRecv-MessRecv)>=256 then write(nMessRecv-MessRecv) else write(' ',nMessRecv-MessRecv) fi ;
    if (nMessSent-MessSent)>=256 then write(nMessSent-MessSent) else write(' ',nMessSent-MessSent) fi ;
    MessRecv:=nMessRecv;   MessSent:=nMessSent;
    write('|');
    if niobCRC<>iobCRC then write (niobCRC-iobCRC) else write('..'); fi;
    if niobErr<>iobErr then write (niobErr-iobErr) else write('..'); fi ;
  fi ;
    iobErr:=niobErr;iobCRC:=niobCRC;
  else write('-');
  fi ;
fi ;
fi ;
