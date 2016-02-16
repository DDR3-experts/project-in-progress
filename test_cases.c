/*timing parameters

tRC 50		
tRAS 36
tRRD 6
tRP 14 --A timing parameter having to do with precharge
tRFC 172
tCWL(tCWD) 10
tCAS (CL) 14  --- cas latency
tRCD 14
tWR 16
tRTP 8
tCCD 4
tBURST 4
tWTR 8

*/

/*DRAM Commmands

ACT<BANK><ROW> //row activate
PRE<BANK> //bank precharge
RD<BANK><COLUMN> //column read
RDAP<BANK><COLUMN> //Read auto precharge
WRAP<BANK><COLUMN> //read auto prechange
REF // refresh -- optional 


//case of a single write on tick 0, no subsequent action by processor
//if not already precharged: READ = Precharge then Activate (wait tRCD, unless additive latency has been correctly preprogrammed) then READ
//See page 150 for a breakdown. If a bank is open, a READ-READ or WRITE-WRITE command is limited by tCCD (not given in specifications)
tRC is min time between successive Activate commands (in one bank)
tRRD is min time between activates to different banks
Read value is available tCAS after row operations.
so READ: Precharge + tRC+tCAS = Time till data is output







