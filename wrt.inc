//val!!! hex
if dig = 0 then 
if val=0 then evalwrite('..')
else
  if val<0 then  evalwrite('??')
  else 
  if val<16 then evalwrite(' ~cd(d[0])',val)
  else
    if val<256 then evalwrite('~cd(d[0])',val)
    else
      if val >2000 then evalwrite('?!') 
      else if val >1000 then evalwrite('2K') 
      else if val >500 then evalwrite('1K') 
      else evalwrite('XX') fi ; fi ; fi
    fi ;
  fi fi ;
fi ;
else // dig = 4
if val=0 then evalwrite('0000')
else
  if val<16 then evalwrite('000~cd(d[0],h)',val)
  else
    if val<256 then evalwrite('00~cd(d[0],h)',val)
    else
      if val <$1000 then evalwrite('0~cd(d[0],h)',val)
      else evalwrite('~cd(d[0],h)',val)
      fi ;
    fi ;
  fi ;
fi ;
fi 