if mod = 0 then
  SetHashFile ('.\Hashes\MyHash.xml');
  SetHashFile('.\Hashes\Common.xml');
  mod:=evalasync('~user("Caption","����� ������ ",300,200)','$20');
  setmask($f);
  //writeln('mod=',mod);
  if (GetTaskSocket>=$1d00) then 
    if (mod =0)||(mod=-1) then
       SetMask($B);SendMess($8000,$FF01,2,$D,$40);
	   settimeout(1000);
       recvmess(a,b,c,d,e,mod);
    fi;
  fi;
  if (mod =0)||(mod=-1) then 
    if default=0 then
	  writeln('���������� ����������� ���������� ������') ; 
	else
	  mod := default;
	fi;  
  fi ;
fi  ;

