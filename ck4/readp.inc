
//slot:=64;           //  ᫮�
//slot:=16;           //  ᫮�
//tr  :=1;            //  䨧��᪨� �ࠪ�

muxbase :=$8000;
crval   :=inword(muxbase);
dmrena  :=crval ||$0010;
port1   :=muxbase +$2000 +(tr <<8)+ (slot<<1);


        setmask($16);

                SendMess((mod*256) +$ff,$AA51,0, // save script from disp 0
                                $0100,  dmrena,
                                $0100,  muxbase,        $5509,  // OutWord(muxbase,dmrena); // Enable DM reading
                                $0100,  port1,          $5508,  // InByte(port); // Idle
                                $0100,  port1,          $5508,  // InByte(port); // Read
                                $0000,  $0002,          $5506,  // SendMess($0000,$0000,$0002); // Send both words to self
                                $0100,  crval,
                                $0100,  muxbase,        $5509,  // OutWord(muxbase,crval); // Restore CR
                                $FFFF                                                                                   // Finish
                                );

        setmask($16);

                SendMess((mod*256) +$ff,$AA52,0);       // Run the script

                RecvMess(msg,val1,val2);

//writeln('read- ',mod,tr,slot,'data', val1,val2 );
