
SetHashFile ('.\Hashes\MyHash.xml');
SetHashFile('.\Hashes\Common.xml');

mod:=(evalasync('~user("Caption","номер модуля - 32=$20, 48=$30, 64=$40, 117=$75",300,200)'));

setmask($f);
//writeln('mod=',mod);
if (mod =0)||(mod=-1) then
  include chkmod.inc ;
fi;

