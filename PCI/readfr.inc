// inc �ᯮ���� 3 ��ࠬ���
// - ����� �३���
// - ���� ॣ���� �� �३���
// - ���祭�� ॣ����
addr:=$4000+(numfr-1)*$1000;
/*
setmask($b);
sendmess(mod*256,$ff01,4,regs,addr);
recvmess(a,b,c,d,e,temp);
write(temp && $FF, (temp && $FF00) >>8 );
*/
setmask(3);
sendmess(mod*256+$fe,4013,addr+regs);
recvmess(t0,t1, temp,a01);
write(temp && $FF, (temp && $FF00) >>8 );
