// addr - адрес dsp 
// w32 - адрес dsp 

basedsp := $6300;

	SendMess(
		(mod*256)+$ff, 	$AA51,0,     // fill script from disp 0
    	$100, basedsp,$8,$100, addr >> 16,	$5507,            		
    	$100, basedsp,$a,$100, addr && $ffff,	$5507,            		
    	$100, basedsp,$4,$100, w32 >> 16,	$5507,            		
    	$100, basedsp,$6,$100, w32 && $ffff,	$5507,            		
		$FFFF );                       

	SendMess((Mod*256)+$ff,$AA52,0);    // Run the script
	
writeln( addr, '<-', w32);