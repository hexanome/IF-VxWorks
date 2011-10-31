#include "stdio.h"
#include "stdlib.h"
#include "iosLib.h"
#include "HelloWorld.h"

#define true 1
#define false 0

static int major = -1;

void setup()
{
	addDrv();
	addDev("/dev1");
}

void use()
{
	int fd = open("/dev1", O_RDWR, 0);
	char buffer[10];
	int nb;
	int i;
	
	if (fd < 0)
	{
		printf("ERROR\n");
		return;
	}
	
	nb = read(fd, buffer, 10);
	for (i = 0; i < nb; i++)
	{
		printf("%c", buffer[i]);
	}
	
	printf("\n");	
	close(fd);
	
	printf("FIN\n");	
}

void destroy()
{
	removeDev("/dev1");
	removeDrv();
}

STATUS addDev(char *name)
{
	MY_DEV *p;
	STATUS status;
	p = (MY_DEV*)malloc(sizeof(MY_DEV));
	status = iosDevAdd((DEV_HDR*)p,name,major);
	return status;
}

STATUS removeDev (char *name)
{
	char *pNameTail;
	DEV_HDR *devHdr = iosDevFind(name,&pNameTail);
	if (!devHdr || !pNameTail || *pNameTail != '\0')
	{
		return -1;
	}
	
	iosDevDelete(devHdr);
	return 0;
}

STATUS myDevCreate (MY_DEV *p,char* additionalInfo,int flag)
{
	return 0;
}

STATUS myDevDelete(MY_DEV *p,char* additionalInfo)
{
	return 0;
}

STATUS myDevOpen (MY_DEV *p,char* additionalInfo,int flag)
{	
	return (int)p;
}

STATUS myDevClose (MY_DEV *p)
{
	return 0;
}

STATUS myDevRead (MY_DEV *p, char *buff, int nBytes) 
{
	int i;
	for (i = 0; i < nBytes; i++)
	{
		buff[i] = 'a';
	}
	
	return nBytes;
}

STATUS myDevWrite (MY_DEV *p, char *buff, int nBytes)
{
	return 0;
}

STATUS myDevIoctl (MY_DEV *p, int fonction, int arg) 
{
	return 0;
}

STATUS addDrv ()
{
	major = iosDrvInstall(myDevCreate,myDevDelete,myDevOpen,myDevClose,myDevRead,myDevWrite,myDevIoctl);
	return 0;
}

STATUS removeDrv ()
{
	return iosDrvRemove(major, true); 
}
