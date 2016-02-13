/*timing parameters

tRC 50
tRAS 36
tRRD 6
tRP 14
tRFC 172
tCWL(tCWD) 10
tCAS (CL) 14
tRCD 14
tWR 16
tRTP 8
tBURST 4
tWTR 8

*/

/*DRAM Commmands

ACT<BANK><ROW> //row activate
PRE<BANK> //bank precharge
RD<BANK><COLUMN> //column read
RDAP<BANK><COLUMN> //???
WRAP<BANK><COLUMN> //???
REF // refresh -- optional 


//case of a single write on tick 0, no subsequent action by processor






