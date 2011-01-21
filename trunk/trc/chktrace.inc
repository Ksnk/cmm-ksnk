 SetMask($b); SendMess(mod*256,$ff01,4,0,$30);
 if recvmess(a,b,c,d,e,f,g)>0 then 
   if f = $4321 then ats := g fi ;
   if f = $1234 then writeln('трасса уже установелна!') ;
     if ats = 0 then // пытаемся найти сегмент
       ats0 := g; // correct AtSeg
       SetMask($b); SendMess(mod*256,$ff01,2,0,ats0);
       if recvmess(a,b,c,d,e,f)>0 then 
         if f = $4321 then ats := ats0 fi ;
       fi ;
     fi ; 
   fi;  
 fi ;
 SetMask($b); SendMess(mod*256,$ff01,2,2,$1b0);
 if recvmess(a,b,c,d,e,f)>0 then 

for i from 0 to 8 do
 if ats = 0 then 
   if i = 0 then ats0:= f+$10 fi ;
   if i = 1 then ats0:= f+$11 fi ;
   if i = 2 then ats0:= f+$12 fi ;
   if i = 3 then ats0:= $1200 fi ;
   if i = 4 then ats0:= $1201 fi ;
   if i = 5 then ats0:= $1400 fi ;
   if i = 6 then ats0:= $3f8  fi ;
   if i = 7 then ats0:= $384  fi ;
   if i = 8 then ats0:= f+$f  fi ;
   
   if ats0<>0 then // writeln('looking for ',ats0);// пытаемся найти сегмент
      SetMask($b); SendMess(mod*256,$ff01,2,0,ats0);
      if recvmess(a,b,c,d,e,x)>0 then 
       if x = $1234 then ats := ats0 fi ;
   fi fi ;
 fi ;
od ; 
fi ;
