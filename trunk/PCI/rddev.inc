writeln(mod,':PCI bus ',bus,' dev ',device);
for j from 0 to $f do 
   k := j*16 ;
  SendMess((Mod*256)+$ff,$AA51,0            //!! 
        ,$100, $8000+bus,$100,(device<<11)+k ,$100,REGA,$5510      //!! outlong (<REGA>,$0001);
        ,$100,$5555
        ,$0,$100,REGD,$5511      //!! inlong (<REGA>,$0001);
        ,$100, $8000+bus,$100,(device<<11)+k+4 ,$100,REGA,$5510      //!! outlong (<REGA>,$0001);
        ,$0,$100,REGD,$5511      //!! inlong (<REGA>,$0001);
        ,$100, $8000+bus,$100,(device<<11)+k+8 ,$100,REGA,$5510      //!! outlong (<REGA>,$0001);
        ,$0,$100,REGD,$5511      //!! inlong (<REGA>,$0001);
        ,$100, $8000+bus,$100,(device<<11)+k+$c ,$100,REGA,$5510      //!! outlong (<REGA>,$0001);
        ,$0,$100,REGD,$5511      //!! inlong (<REGA>,$0001);
		,0,9,$5506
        ,$FFFF);                          //!! 
  SendMess((Mod*256)+$ff,$AA52,0);          //!! 
  recvmess(a,b,c,d,e,f,g,h,l,m);
  dig := 4;
  val := k;include wrt.inc;
  write(':');
  val := c && $ffff; include wrt.inc;
  val := d && $ffff; include wrt.inc; 
  write('');
  val := e && $ffff; include wrt.inc;
  val := f && $ffff; include wrt.inc; 
  write('');
  val := g && $ffff; include wrt.inc;
  val := h && $ffff; include wrt.inc; 
  write('');
  val := l && $ffff; include wrt.inc;
  val := m && $ffff; include wrt.inc; 
  writeln(' ');

od;
