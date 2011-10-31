typedef struct
{
	DEV_HDR myDevHdr;	
} MY_DEV;

STATUS addDev(char *name);
STATUS removeDev (char *name);
STATUS myDevCreate (MY_DEV *p,char* additionalInfo,int flag);
STATUS myDevDelete(MY_DEV *p,char* additionalInfo);
STATUS myDevOpen (MY_DEV *p,char* additionalInfo,int flag);
STATUS myDevClose (MY_DEV *p);
STATUS myDevRead (MY_DEV *p, char *buff, int nBytes);
STATUS myDevWrite (MY_DEV *p, char *buff, int nBytes);
STATUS myDevIoctl (MY_DEV *p, int fonction, int arg);
STATUS addDrv();
STATUS removeDrv();
