// Mod - внешняя настройка
// Остальные настройки - из test-os

sendmess(Mod*256+$ff,$aa00);
lover := 0 ;
if nowrite=0 then write(' модуль ', mod,'-'); fi ;
if recvmess(a,b,c,d,e,f,hiver,lover,loplus)>0 then

if hiver = $322e then // версия .2
  if lover = $3130 then
    writeln ('обнаружена версия ос 3.201');
    IOMOD_dsp := -$209;
    CHAN_dsp  := $219;
    ERR_dsp   := $23c ;
    ALIVE_dsp := -$2 ;
    CND_dsp   := 5;
  //  QUEUE_dsp := $215 ;//-CHAN_dsp=-4
    QUEUE_dsp := $20b ;// Невского - 2

  fi ;

  if lover = $3031 then
    writeln ('обнаружена версия ос 3.210');
    IOMOD_dsp := $10;
    CHAN_dsp  := $14 ;
    ERR_dsp   := $3f ;
    ALIVE_dsp := $21a ;
    CND_dsp   := 7 ;
    QUEUE_dsp := $10 ;//-CHAN_dsp=-4
  fi ;

  if lover = $3231 then
    if loplus = $3128 then
      writeln ('обнаружена версия ос 3.212(-)');
      IOMOD_dsp := $10;
      ALIVE_dsp := $21e ;
    else
      writeln ('обнаружена версия ос 3.212');
      IOMOD_dsp := $14;
     ALIVE_dsp := $222 ;
   fi;
//    writeln ('обнаружена версия ос 3.212');
    CHAN_dsp  := $14 ;
    ERR_dsp   := $3f ;
    CND_dsp   := 7 ;
    QUEUE_dsp := $10 ;//-CHAN_dsp=-4
  fi ;

  if lover = $3431 then
    if (loplus && $FF) = $2b then
      writeln ('обнаружена версия ос 3.214+');
      IOMOD_dsp := $16;
    else
      writeln ('обнаружена версия ос 3.214');
      IOMOD_dsp := $14;
    fi;
    CHAN_dsp  := $14 ;
    ERR_dsp   := $3f ;
    ALIVE_dsp := $224 ;
    CND_dsp   := 7 ;
    QUEUE_dsp := $10 ;//-CHAN_dsp=-4
  fi ;
  if lover = $3531 then
    writeln ('обнаружена версия ос 3.215');
    IOMOD_dsp := $16;
    CHAN_dsp  := $14 ;
    ERR_dsp   := $3f ;
    ALIVE_dsp := $224 ;
    CND_dsp   := 7 ;
    QUEUE_dsp := $10 ;//-CHAN_dsp=-4
  fi ;
  if lover = $3731 then
    writeln ('обнаружена версия ос 3.217');
    IOMOD_dsp := $16;
    CHAN_dsp  := $14 ;
    ERR_dsp   := $3f ;
    ALIVE_dsp := $224 ;
    CND_dsp   := 7 ;
    QUEUE_dsp := $10 ;//-CHAN_dsp=-4
  fi ;
  if lover = $3931 then
    writeln ('обнаружена версия ос 3.219');
    IOMOD_dsp := $16;
    CHAN_dsp  := $14 ;
    ERR_dsp   := $3f ;
    ALIVE_dsp := $128 ;
    CND_dsp   := 7 ;
    QUEUE_dsp := $10 ;//-CHAN_dsp=-4
  fi ;
  if lover = $3032 then
    writeln ('обнаружена версия ос 3.220');
    IOMOD_dsp := $18;  // !!!
    CHAN_dsp  := $14 ;
    ERR_dsp   := $3f ;
    ALIVE_dsp := $12A ; // !!!
    CND_dsp   := 8 ;
    QUEUE_dsp := $10 ;//-CHAN_dsp=-4
  fi ;
  if lover = $3132 then
    if nowrite=0 then writeln ('обнаружена версия ос 3.221'); fi ;
    IOMOD_dsp := $18;  // !!!
    CHAN_dsp  := $14 ;
    ERR_dsp   := $3f ;
    ALIVE_dsp := $12A ; // !!!
    CND_dsp   := 10 ;
    QUEUE_dsp := $10 ;//-CHAN_dsp=-4
  fi ;
fi  ;

if IOMOD_dsp = 0 then
   writeln('неизвестная версия ОС!!!!!!!!!', lover);
   IOMOD_dsp := $16;
   CHAN_dsp  := $14 ;
   ERR_dsp   := $3f ;
   ALIVE_dsp := $224 ;
   CND_dsp   := 7 ;
   QUEUE_dsp := $10 ;//-CHAN_dsp=-4
fi ;
fi ;


if lover = 0 then
   lover := 0 ;
   writeln('нет ответа от модуля !!!!!!');
   IOMOD_dsp := $16;
   CHAN_dsp  := $14 ;
   ERR_dsp   := $3f ;
   ALIVE_dsp := $224 ;
   CND_dsp   := 7 ;
   QUEUE_dsp := $10 ;//-CHAN_dsp=-4
fi ;