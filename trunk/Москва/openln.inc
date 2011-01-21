// ln

SetTimeout( 10000 );
SetHashFile( '.\Hashes\MyHash.xml' );

ofs:= Evaluate( '~fpoGetOfs( ln, implementation )' );

SendMess( ( LN && $FF00 ) + $FE, 1028, LN, ofs, 2 );
if RecvMess( a, b, c, d, e, implementation0 ) <> 0 then

            implementation := implementation0 ||2 ; && $fffd ;//|| 2;

//;
//|| 2;

   SendMess( ( LN && $FF00 ) + $FE, 1030, LN, ofs, 2, implementation );
   RecvMess( a );
   writeln('LN',LN, '::', implementation0,'заменено на',implementation);

fi;
//   SendMess( ( LN && $FF00 ) + $FE, 1029, LN, ofs, 2, implementation );
