if mod = 0 then
  SetHashFile ('.\Hashes\MyHash.xml');
  SetHashFile('.\Hashes\Common.xml');
  Client := GetTaskSocket>>8 ;
  mod:=evalasync('~user("Caption","����� ������ ",300,200)');
  setmask($f);
  //writeln('mod=',mod);
  if (Client>=$1d) then 
    if (mod =0)||(mod=-1) then
       SetMask($B);SendMess($8000,$FF01,2,$D,$40);
       recvmess(a,b,c,d,e,mod)
    fi;
  fi;
  if (mod =0)||(mod=-1) then writeln('���������� ����������� ���������� ������') ; fi ;
fi  ;

