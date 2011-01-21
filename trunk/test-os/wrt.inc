//val!!! hex
if val=0 then evalwrite('..')
else
  if val<16 then evalwrite(' ~cd(d[0])',val)
  else
    if val<256 then evalwrite('~cd(d[0])',val)
    else
      if val >1000 then evalwrite('??') else evalwrite('XX') fi ;
    fi ;
  fi ;
fi ;