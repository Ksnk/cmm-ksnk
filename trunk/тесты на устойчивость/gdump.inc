if len = 0 then goto fin fi ;
setmask($b);
for i from 0 to len /8 do
 lp_again:
 SendMess(mod*256,$FF01,16,0,start+i);
 if recvmess(a,b,c,d,e,a1,a2,a3,a4,a5,a6,a7,a8)>0 then START6 := $32f4  ; Len6 := $80;
   if (e<>start+i) then goto lp_again 
  fi ;
 else goto lp_again fi ;
 write  (start,':'); if i < $10 then write(' ') fi ;
 write  (i*$10,'|');
 write  (a1&&$ff,a1/256  );
 write  (a2&&$ff,a2/256  );
 write  (a3&&$ff,a3/256  );
 write  (a4&&$ff,a4/256  );
 write  (a5&&$ff,a5/256  );
 write  (a6&&$ff,a6/256  );
 write  (a7&&$ff,a7/256  );
 writeln(a8&&$ff,a8/256  );

//,a1,a2,a3,a4,a5,a6,a7,a8);
od;