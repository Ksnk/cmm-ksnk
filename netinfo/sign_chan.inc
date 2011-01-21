disp := 0 ;
if displ <> 0 then
  displ := displ +4 ;
  if channum = 0 then
    setmask($b);sendmess(Mod*256,$FF01,4,displ,$1b0);
    recvmess(a,b,c,d,e,queue, mmm); //write(queue, mmm);
    if queue = 0 then displ := 0
    else
      module := 0 ;
      setmask($b);sendmess(Mod*256,$FF01,2,queue-$e,$1b0);
      recvmess(a,b,c,d,e,sig);

      lastqueue := queue ;
//      ssig = (sig && $ff);
      if ((sig && $ff) = $64)||((sig && $ff) = 30)||((sig && $ff) = 40) then
        write('// найден IO_BETA для модуля', mmm);
        chan :=mmm;

        setmask($b);sendmess(Mod*256,$FF01,4,queue-$16,$1b0);
        recvmess(a,b,c,d,e,a1,a2); if (a1=a2)&&(a1<>0) then write('тракт', a1); fi ;
   // читаем количество ошибок
        disp := queue+ALIVE_dsp ;
        setmask($b);sendmess(Mod*256,$FF01,12,disp,$1b0);
        recvmess(a,b,c,d,e,Alive,MessRecv,f,iobCRC,MessSent,iobErr);

        if Alive <> 0 then
          write ('+');
        else
          write('!!! мертвый канал!!!!!!!!!!!');
          if IgnoreDead <> 1 then writeln; disp := 0 fi;
        fi
      
      else
        setmask($b);sendmess(Mod*256,$FF01,32,queue-2,$1b0);
        recvmess(a,b,c,d,e,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16);
        a1 := a1 >>8 ;
        sig := 0 ; 
        if (a1>$1000) then
           if a1=8 then sig :=sig && (a6 >$1000) &&(a7>$1000) &&(a8>$1000) &&(a9>$1000) &&(a10>$1000) &&(a11>$1000) &&(a12>$1000) &&(a13>$1000)  fi ;   
           if a1=7 then sig :=sig && (a6 >$1000) &&(a7>$1000) &&(a8>$1000) &&(a9>$1000) &&(a10>$1000) &&(a11>$1000) &&(a12>$1000) &&(a13=0)  fi ;   
           if a1=6 then sig :=sig && (a6 >$1000) &&(a7>$1000) &&(a8>$1000) &&(a9>$1000) &&(a10>$1000) &&(a11>$1000) &&(a12=0) &&(a13=0)  fi ;   
           if a1=5 then sig :=sig && (a6 >$1000) &&(a7>$1000) &&(a8>$1000) &&(a9>$1000) &&(a10>$1000) &&(a11=0) &&(a12=0) &&(a13=0)  fi ;   
           if a1=4 then sig :=sig && (a6 >$1000) &&(a7>$1000) &&(a8>$1000) &&(a9>$1000) &&(a10=0) &&(a11=0) &&(a12=0) &&(a13=0)  fi ;   
           if a1=3 then sig :=sig && (a6 >$1000) &&(a7>$1000) &&(a8>$1000) &&(a9=0) &&(a10=0) &&(a11=0) &&(a12=0) &&(a13=0)  fi ;   
           if a1=2 then sig :=sig && (a6 >$1000) &&(a7>$1000) &&(a8=0) &&(a9=0) &&(a10=0) &&(a11=0) &&(a12=0) &&(a13=0)  fi ;   
        fi ;

        if (sig=0) then  //;(mod*256+$ff)) then
        setmask($b);sendmess(Mod*256,$FF01,1,queue-14,$1b0);
        recvmess(a,b,c,d,e,module);//write('!',module,mmm);
//        if (module && $ff) = mmm then
          chan :=mmm;
          if ( mmm && $ff00) <> $100 then

          write('// найден MTP канал для', mmm);
          disp := $8000+queue-11 ;
          setmask($b);sendmess(Mod*256,$FF01,12,disp-$8000,$1b0);
          recvmess(a,b,c,d,e,Alive,DPC,SLS,MessRecv,MessSent);
//          writeln(Alive,DPC,SLS,MessRecv,MessSent);
        if Alive = 0 then
          write ('+');
        else
          writeln ('!!! мертвый канал!!!!!!!!!!!');
          disp := 0 ;
        fi
          fi   
        else
          if mmm<$100 then

            setmask($b);sendmess(Mod*256,$FF01,1,queue-1,$1b0);
            recvmess(a,b,c,d,e,channum);
            writeln ('// найден пучек для ',mmm,' длиной ', channum);
            i := 2 ;    chdisp :=  queue ;
            setmask($b);sendmess(Mod*256,$FF01,2,queue+CND_dsp+(2),$1b0);
            recvmess(a,b,c,d,e,IOBUF);queue := IOBUF+QUEUE_dsp ;
        chan :=mmm;
   // читаем количество ошибок
        disp := queue+ALIVE_dsp ;
        setmask($b);sendmess(Mod*256,$FF01,4,queue-$16,$1b0);
        recvmess(a,b,c,d,e,a1,a2); if (a1=a2)&&(a1<>0) then write('тракт', a1); fi ;
        setmask($b);sendmess(Mod*256,$FF01,12,disp,$1b0);
        recvmess(a,b,c,d,e,Alive,MessRecv,f,iobCRC,MessSent,iobErr);
        write('Найден пучек ', mmm);
        if Alive <> 0 then
          write ('+');
        else
          write ('!!! мертвый канал!!!!!!!!!!!');
          if IgnoreDead <> 1 then writeln; disp := 0 fi;
        fi
          fi ;
        fi ;
      fi;
    fi ;
  else
    setmask($b);sendmess(Mod*256,$FF01,2,chdisp+CND_dsp+(2*i),$1b0);
        recvmess(a,b,c,d,e,IOBUF);queue := IOBUF+QUEUE_dsp ;
        chan :=mmm;
   // читаем количество ошибок
        disp := queue+ALIVE_dsp ;
        setmask($b);sendmess(Mod*256,$FF01,12,disp,$1b0);
        recvmess(a,b,c,d,e,Alive,MessRecv,f,iobCRC,MessSent,iobErr);
        write('Найден пучек ', mmm);
        if Alive <> 0 then
          write ('+');
        else
          writeln ('!!! мертвый канал!!!!!!!!!!!');
          if IgnoreDead <> 1 then  disp := 0 fi;
        fi ;
    i := i+1 ;
    if i > channum then channum := 0  fi ;
  fi
fi;

//DUP founds!
if disp > 0 then
  if disp <> 0 && disp = disp01 then writeln('dup found',chan01) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp02 then writeln('dup found',chan02) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp03 then writeln('dup found',chan03) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp04 then writeln('dup found',chan04) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp05 then writeln('dup found',chan05) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp06 then writeln('dup found',chan06) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp07 then writeln('dup found',chan07) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp08 then writeln('dup found',chan08) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp09 then writeln('dup found',chan09) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp10 then writeln('dup found',chan10) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp11 then writeln('dup found',chan11) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp12 then writeln('dup found',chan12) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp13 then writeln('dup found',chan13) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp14 then writeln('dup found',chan14) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp15 then writeln('dup found',chan15) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp16 then writeln('dup found',chan16) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp17 then writeln('dup found',chan17) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp18 then writeln('dup found',chan18) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp19 then writeln('dup found',chan19) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp20 then writeln('dup found',chan20) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp21 then writeln('dup found',chan21) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp22 then writeln('dup found',chan22) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp23 then writeln('dup found',chan23) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp24 then writeln('dup found',chan24) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp25 then writeln('dup found',chan25) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp26 then writeln('dup found',chan26) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp27 then writeln('dup found',chan27) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp28 then writeln('dup found',chan28) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp29 then writeln('dup found',chan29) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp30 then writeln('dup found',chan30) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp31 then writeln('dup found',chan31) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp32 then writeln('dup found',chan32) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp33 then writeln('dup found',chan33) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp34 then writeln('dup found',chan34) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp35 then writeln('dup found',chan35) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp36 then writeln('dup found',chan36) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp37 then writeln('dup found',chan37) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp38 then writeln('dup found',chan38) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp39 then writeln('dup found',chan39) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp40 then writeln('dup found',chan40) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp41 then writeln('dup found',chan41) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp42 then writeln('dup found',chan42) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp43 then writeln('dup found',chan43) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp44 then writeln('dup found',chan44) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp45 then writeln('dup found',chan45) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp46 then writeln('dup found',chan46) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp47 then writeln('dup found',chan47) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp48 then writeln('dup found',chan48) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp49 then writeln('dup found',chan49) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp50 then writeln('dup found',chan50) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp51 then writeln('dup found',chan51) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp52 then writeln('dup found',chan52) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp53 then writeln('dup found',chan53) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp54 then writeln('dup found',chan54) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp55 then writeln('dup found',chan55) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp56 then writeln('dup found',chan56) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp57 then writeln('dup found',chan57) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp58 then writeln('dup found',chan58) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp59 then writeln('dup found',chan59) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp60 then writeln('dup found',chan60) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp61 then writeln('dup found',chan61) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp62 then writeln('dup found',chan62) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp63 then writeln('dup found',chan63) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp64 then writeln('dup found',chan64) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp65 then writeln('dup found',chan65) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp66 then writeln('dup found',chan66) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp67 then writeln('dup found',chan67) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp68 then writeln('dup found',chan68) ; disp := 0 ; fi ;
  if disp <> 0 && disp = disp69 then writeln('dup found',chan69) ; disp := 0 ; fi ;
  if disp > 0 then writeln fi ;
fi ;
