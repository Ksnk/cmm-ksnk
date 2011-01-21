disp := 0 ;
if displ <> 0 then
  if channum = 0 then
    setmask($b);sendmess(Mod*256,$FF01,4,displ,$1b0);
    recvmess(a,b,c,d,e,queue, mmm); //write(queue, mmm);
    for i from 1 to 30 do
      if queue = lastqueue then
        displ := displ +4 ;

        mmm := 0 ;
        setmask($b);sendmess(Mod*256,$FF01,4,displ,$1b0);
        recvmess(a,b,c,d,e,queue, mmm);
      fi
    od ;
    if queue = 0 then displ := 0
    else
      module := 0 ;
      setmask($b);sendmess(Mod*256,$FF01,1,queue+IOMOD_dsp,$1b0);
      recvmess(a,b,c,d,e,module);
//      writeln(module,mmm,mod,queue);

      lastqueue := queue ;

      if module = mod then
        write('// найден IO_BETA для модуля', mmm);
        chan :=mmm;
   // читаем количество ошибок
        disp := queue+ALIVE_dsp ;
        setmask($b);sendmess(Mod*256,$FF01,12,disp,$1b0);
        recvmess(a,b,c,d,e,Alive,MessRecv,f,iobCRC,MessSent,iobErr);

        if Alive <> 0 then
          writeln ('+');
        else
          writeln ('!!! мертвый канал!!!!!!!!!!!');
          disp := 0 ;
        fi
//        Evalwrite('chan :=~cd(d[0]);Err :=~cd(d[4]); disp :=~cd(d[8]); include check.inc ; ' ,chan, error,queue-$3f);
//        writeln(' // ');
      //  EvalWrite('modto:=~cd(d[0]); SendMess( modto, 1030, ~cd(d[4]), ~cd(d[52]), 22,~cd(d[8]),~cd(d[12]),~cd(d[16]),~cd(d[20]),~cd(d[24]),~cd(d[28]),~cd(d[32]),~cd(d[36]),~cd(d[40]),~cd(d[44]),~cd(d[48]));RecvMess;',modto, Obj, k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,ofski );

      else
        setmask($b);sendmess(Mod*256,$FF01,1,queue-14,$1b0);
        recvmess(a,b,c,d,e,module);//write('!',module,mmm);
        if module = mmm then
          chan :=mmm;

          write('// найден MTP канал для', mmm);
          disp := $8000+queue-11 ;
          setmask($b);sendmess(Mod*256,$FF01,12,disp-$8000,$1b0);
          recvmess(a,b,c,d,e,Alive,DPC,SLS,MessRecv,MessSent);
//          writeln(Alive,DPC,SLS,MessRecv,MessSent);
        if Alive = 0 then
          writeln ('+');
        else
          writeln ('!!! мертвый канал!!!!!!!!!!!');
          disp := 0 ;
        fi
        fi ;
      fi;
    fi ;
    i := i+1 ;
    if i > channum then channum := 0  fi ;
  fi
fi