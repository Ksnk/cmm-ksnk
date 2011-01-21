if len <> 0 then 
setmask($b);
for i from 0 to len /16 do
 ready := 0 ;
 for ii from 0 to 8 do
   if ready=0 then ready := 1; 
     if START_DEBUG=1 then SendMess(mod*256+$ff,4444); fi ;
     SendMess(mod*256,$FF01,32,0,start+(2*i));
     if recvmess(a,b,c,d,e,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16)>0 then START6 := $32f4  ; Len6 := $80;
       if (e<>start+(2*i)) then ready:=0  fi ;
     else ready:=0 fi ;
   fi ;
 od ;

// Evalwrite('~h(d[0]):' ,start);
 val := start ; dig := 4 ; include wrt.inc;
 evalwrite(':'); 
 val := 2*i*$10 ; dig := 4 ; include wrt.inc;
 write(' ') ;

 writeln  (a1&&$ff,a1/256,a2&&$ff,a2/256,a3&&$ff,a3/256,a4&&$ff,a4/256,  
           a5&&$ff,a5/256,a6&&$ff,a6/256,a7&&$ff,a7/256,a8&&$ff,a8/256  );

 if (2*i+1)<=(len/8) then 
 val := start ; dig := 4 ; include wrt.inc;
 evalwrite(':'); 
 val := (2*i+1)*$10 ; dig := 4 ; include wrt.inc;
 write(' ') ;
 writeln  (a9&&$ff,a9/256 ,a10&&$ff,a10/256,a11&&$ff,a11/256,a12&&$ff,a12/256,
         a13&&$ff,a13/256,a14&&$ff,a14/256,a15&&$ff,a15/256,a16&&$ff,a16/256  );

 fi ;

od;

fi ;

