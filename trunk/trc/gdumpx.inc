if len <> 0 then 

for i from 0 to len /32 do
 ready := 0 ;
 for ii from 0 to 8 do
   if ready=0 then ready := 1; 
     if START_DEBUG=1 then SendMess(mod*256+$ff,4444); fi ;
seg:= start;x := $20*i ;
SendMess((Mod*256)+$ff,$AA51,0            //!! 
        ,$100,x                           //!! push <x> ;
        ,$100,seg                         //!! push <seg>
        ,$100,seg,$100,x,$10,$550f      //!! RDMEMC(<seg>:<x>,$10);
        ,0,$12,$5506                      //!! send(0,*,*,*,*, *,*,*,*, *,*,*,*, *,*,*,*, *,*)
        ,$100,x                           //!! push <x> ;
        ,$100,seg                         //!! push <seg>
        ,$100,seg,$100,x,$10,$550f      //!! RDMEMC(<seg>:<x>,$10);
        ,0,$12,$5506                      //!! send(0,*,*,*,*, *,*,*,*, *,*,*,*, *,*,*,*, *,*)
        ,$FFFF);                          //!! 
SendMess((Mod*256)+$ff,$AA52,0);          //!! 

     recvmess(a,b,c,a1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16); 
     if recvmess(a,b,c,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16)>0 then 
       if (b<>($20*i)) then ready:=0  fi ;
     else ready:=0 fi ;
   fi ;
 od ;

 val := start ; dig := 4 ; include wrt.inc;
 evalwrite(':'); 
 val := 4*i*$10 ; dig := 4 ; include wrt.inc;
 write(' ') ;

 writeln  (b1&&$ff,b1/256,b2&&$ff,b2/256,b3&&$ff,b3/256,b4&&$ff,b4/256,  
           b5&&$ff,b5/256,b6&&$ff,b6/256,b7&&$ff,b7/256,b8&&$ff,b8/256  );

 val := start ; dig := 4 ; include wrt.inc;
 evalwrite(':'); 
 val := (4*i+1)*$10 ; dig := 4 ; include wrt.inc;
 write(' ') ;
 writeln  (b9&&$ff,b9/256 ,b10&&$ff,b10/256,b11&&$ff,b11/256,b12&&$ff,b12/256,
         b13&&$ff,b13/256,b14&&$ff,b14/256,b15&&$ff,b15/256,b16&&$ff,b16/256  );

 val := start ; dig := 4 ; include wrt.inc;
 evalwrite(':'); 
 val := (4*i+2)*$10 ; dig := 4 ; include wrt.inc;
 write(' ') ;

 writeln  (a1&&$ff,a1/256,a2&&$ff,a2/256,a3&&$ff,a3/256,a4&&$ff,a4/256,  
           a5&&$ff,a5/256,a6&&$ff,a6/256,a7&&$ff,a7/256,a8&&$ff,a8/256  );

 val := start ; dig := 4 ; include wrt.inc;
 evalwrite(':'); 
 val := (4*i+3)*$10 ; dig := 4 ; include wrt.inc;
 write(' ') ;
 writeln  (a9&&$ff,a9/256 ,a10&&$ff,a10/256,a11&&$ff,a11/256,a12&&$ff,a12/256,
         a13&&$ff,a13/256,a14&&$ff,a14/256,a15&&$ff,a15/256,a16&&$ff,a16/256  );

od;

fi ;

