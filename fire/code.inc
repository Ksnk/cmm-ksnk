if variant=0 then // £„ß®¨ ‰†©´
    oscnt:=(evalasync('~user("Caption","1	-os_test       	2	-os_csl9u     	3	-os_csl9       	4	-os_csl8trn 
5	-os_csl8       	6	-os_csl10     	7	-os_ck8b       	8	-os_ck4trn   
9	-os_ck4         	10	-os_01           	",600,200)'));
fi ;
if variant=1 then // CRC & OS_SIZE
  if  oscnt=1 then  type:=23; OS_SIZE:=$0C00; OS_CRC:=$8404;fi ;
  if  oscnt=2 then  type:=35; OS_SIZE:=$1000; OS_CRC:=$94F6;fi ;
  if  oscnt=3 then  type:=30; OS_SIZE:=$0C00; OS_CRC:=$6994;fi ;
  if  oscnt=4 then  type:=21; OS_SIZE:=$0C00; OS_CRC:=$0BC0;fi ;
  if  oscnt=5 then  type:=18; OS_SIZE:=$0C00; OS_CRC:=$4C97;fi ;
  if  oscnt=6 then  type:=33; OS_SIZE:=$0C00; OS_CRC:=$8E86;fi ;
  if  oscnt=7 then  type:=34; OS_SIZE:=$0800; OS_CRC:=$B494;fi ;
  if  oscnt=8 then  type:=20; OS_SIZE:=$0C00; OS_CRC:=$FFDB;fi ;
  if  oscnt=9 then  type:=15; OS_SIZE:=$0C00; OS_CRC:=$79FA;fi ;
  if  oscnt=10 then  type:=1; OS_SIZE:=$0800; OS_CRC:=$1CDC;fi ;
fi ;
if variant=2 then // loadit!
  if  oscnt=1 then  writeln('Loading file:os_test');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_test',Mod*256,StartArea)  fi ;
  if  oscnt=2 then  writeln('Loading file:os_csl9u');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_csl9u',Mod*256,StartArea)  fi ;
  if  oscnt=3 then  writeln('Loading file:os_csl9');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_csl9',Mod*256,StartArea)  fi ;
  if  oscnt=4 then  writeln('Loading file:os_csl8trn');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_csl8trn',Mod*256,StartArea)  fi ;
  if  oscnt=5 then  writeln('Loading file:os_csl8');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_csl8',Mod*256,StartArea)  fi ;
  if  oscnt=6 then  writeln('Loading file:os_csl10');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_csl10',Mod*256,StartArea)  fi ;
  if  oscnt=7 then  writeln('Loading file:os_ck8b');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_ck8b',Mod*256,StartArea)  fi ;
  if  oscnt=8 then  writeln('Loading file:os_ck4trn');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_ck4trn',Mod*256,StartArea)  fi ;
  if  oscnt=9 then  writeln('Loading file:os_ck4');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_ck4',Mod*256,StartArea)  fi ;
  if  oscnt=10 then  writeln('Loading file:os_01');LoadFile('D:\Program Files\À¿Õ»“-“≈– ŒÃ\–ÃŒ ¿“—  ¬¿Õ“-≈\CMM\ksnk\fire\os_01',Mod*256,StartArea)  fi ;
fi ;
if variant=3 then // oscnt
  if  type=23 then   oscnt :=1; write('os_test');vcnt:=vcnt+1; fi ;
  if  type=35 then   oscnt :=2; write('os_csl9u');vcnt:=vcnt+1; fi ;
  if  type=30 then   oscnt :=3; write('os_csl9');vcnt:=vcnt+1; fi ;
  if  type=21 then   oscnt :=4; write('os_csl8trn');vcnt:=vcnt+1; fi ;
  if  type=18 then   oscnt :=5; write('os_csl8');vcnt:=vcnt+1; fi ;
  if  type=33 then   oscnt :=6; write('os_csl10');vcnt:=vcnt+1; fi ;
  if  type=34 then   oscnt :=7; write('os_ck8b');vcnt:=vcnt+1; fi ;
  if  type=20 then   oscnt :=8; write('os_ck4trn');vcnt:=vcnt+1; fi ;
  if  type=15 then   oscnt :=9; write('os_ck4');vcnt:=vcnt+1; fi ;
  if  type=1 then   oscnt :=10; write('os_01');vcnt:=vcnt+1; fi ;
fi ;
