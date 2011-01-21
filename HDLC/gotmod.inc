
SetHashFile ('.\Hashes\MyHash.xml');
SetHashFile('.\Hashes\Common.xml');

mod:=(evalasync('~user("Caption","номер модуля - 32=$20, 48=$30, 64=$40, 117=$75",300,200)'));
xmod:= mod ;

setmask($f);
//writeln('mod=',mod);
if (mod =0)||(mod=-1) then
     SetMask($B);SendMess($8000,$FF01,2,$D,$40);
     recvmess(a,b,c,d,e,mod);
fi;

