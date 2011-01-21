
SetTimeout( 10000 );
SendMess( ( LN && $FF00 ) + $FE, 1028, LN, $3a, 2 );
_TO := ( LN && $FF00 ) + $FE ;
if RecvMess( a, b, c, d, e, ND ) <> 0 then
if VARIANT= 1 then 
// ***************************************
// смотрим бит в LN И DN
	SendMess( _TO, 1028, LN, $1f, 1 );
	RecvMess( a, b, c, d, e, bit );
	SendMess( _TO, 1028, LN, $2f, 1 );
	RecvMess( a, b, c, d, e, kValue );
	SendMess( _TO, 1028, ND, $e8, 2 );
	RecvMess( a, b, c, d, e, bit2 );

	write(Ln,'x',ND,'--'); 
	if (bit && 1) <> ((bit2 >> 12)&& 1) then write('+') else write('-') fi ;
	writeln(bit,'--',bit2,'(',kValue,')');
fi;
if VARIANT= 2 then 
// ***************************************
// открываем трассу в LN, ND и TO
	SendMess( _TO, 1030, LN, 1,1,  $e0 );
	RecvMess( a);
	SendMess( _TO, 1030, ND, 1,1,  $e0 );
	RecvMess( a);
	SendMess( _TO, 1030, _TO, 1,1,  $e0 );
	RecvMess( a);
  write('+');
fi ;
if VARIANT= 3 then 
// ***************************************
// Устанавливаем kValue в 8
	SendMess( _TO, 1028, LN, $2f, 1 );
	RecvMess( a, b, c, d, e, kValue );
  if kValue<>8 then 
	SendMess( _TO, 1029, LN, $2f,1,  8 );
	RecvMess( a);
	fi ;
  write('+',kValue);
fi ;
//   SendMess( ( LN && $FF00 ) + $FE, 1029, LN, ofs, 2, implementation );
fi;
