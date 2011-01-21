if variant=1 then 
  include ot.cmm ;
fi ;
if variant=2 then 
  include checkmod.cmm ;
fi ;
if variant=3 then 
  include check_traces.cmm ;
fi ;
if variant=4 then 
  include CloseOD.cmm ;
fi ;
if variant=0 then 
   include ver.inc; 
fi ;
