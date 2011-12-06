// addr - адрес dsp 

basedsp := $6300;

	SendMess(
		(mod*256)+$ff, 	$AA51,0,     // fill script from disp 0
    	$100, basedsp,$8,$100, addr >> 16,	$5507,            		
    	$100, basedsp,$a,$100, addr && $ffff,	$5507,            		
		$FFFF );                       

	SendMess((Mod*256)+$ff,$AA52,0);    // Run the script
	
	setmask($b); sendmess(mod*256,$ff01,2,$4,$6300); recvmess(a,b,c,d,e,f1,g);
	setmask($b); sendmess(mod*256,$ff01,2,$6,$6300); recvmess(a,b,c,d,e,f2,g);

	writeln(addr,'=',f1,f2);
