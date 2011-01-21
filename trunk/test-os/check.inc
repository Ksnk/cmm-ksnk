//mod := 01 ;chan :=25;Err :=4; disp :=14451;

if disp > $8000 then // MTP chan
  setmask($b);sendmess(Mod*256,$FF01,12,disp-$8000,$1b0);
  if recvmess(a,b,c,d,e,Alive,DPC,SLS,nMessRecv,nMessSent)>0 then
    if Show=1 then evalwrite('||~cd(d[0],h)', chan) ;
      if Alive=0 then evalwrite('+') else evalwrite('-') fi ;
      val := nMessRecv-MessRecv ; include wrt.inc ;
      val := nMessSent-MessSent ; include wrt.inc ;
    else 
      if Alive=0 then evalwrite('++') else evalwrite('--') fi ;
    fi ;
    MessRecv:=nMessRecv;   MessSent:=nMessSent;
  else evalwrite('--');
  fi ;
else
if disp <> 0 then
  setmask($b);sendmess(Mod*256,$FF01,12,disp,$1b0);
  if recvmess(a,b,c,d,e,Alive,nMessRecv,f,niobCRC,nMessSent,niobErr)>0 then
    if Show=1 then evalwrite('||~cd(d[0],h)', chan)  ;
         if Alive<>0 then evalwrite('+') else evalwrite('-') fi ;
    fi; 
  if Show=1 then 
    val := nMessRecv-MessRecv ; include wrt.inc ;
    val := nMessSent-MessSent ; include wrt.inc ;
    MessRecv:=nMessRecv;   MessSent:=nMessSent;
    evalwrite('|');
    val := niobCRC-iobCRC ; include wrt.inc ;
    val := niobErr<>iobErr ; include wrt.inc ;
  else
    if Alive<>0 then 
      val := niobCRC-iobCRC ; include wrt.inc ;
      val := niobErr<>iobErr ; include wrt.inc ;
    else evalwrite('--')
    fi ;
  fi ;
    iobErr:=niobErr;iobCRC:=niobCRC;
  else evalwrite('-');
  fi ;
fi ;
fi ;
