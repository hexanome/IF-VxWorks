#ifndef __SENSOR_DRIVER_H__
#define __SENSOR_DRIVER_H__

#include <vxworks.h>
#include <taskLib.h>
#include <semLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iosLib.h>
#include <string.h>
#include <time.h>

#include "../sensorDevice/sensorDevice.h"

#define true 1
#define false 0
#define ID_SIZE sizeof(int)
#define TIME_SIZE sizeof(long)
#define VALUE_SIZE 2

typedef struct
{
	int id;
	long timevalue;
	char value[2];
} LAST_READ_VALUE;

typedef struct
{
	DEV_HDR myDevHdr;
	char sensorId[2];
	int openCount;
	LAST_READ_VALUE lastReadValue;	
} SENSOR_DEV;

typedef struct 
{
	SENSOR_DEV* sensorDev;
	char* nextElt;
} SENSOR_DEV_ELT;

static int driverNumber = -1;
static SENSOR_DEV_ELT* deviceList = NULL;
SEM_ID semDeviceList;

STATUS installDrv();
STATUS uninstallDrv();
STATUS addDev(char* devName, char* sensorId);
STATUS removeDev(char* devName);

STATUS sensorOpen(SENSOR_DEV *p, char* pNameTail, int flag);
STATUS sensorClose(SENSOR_DEV *p);
STATUS sensorRead(SENSOR_DEV *p, char *buff, int nBytes);
STATUS sensorIoctl(SENSOR_DEV *p, int fonction, int arg);

void receiveSensorInterrupt();

#endif
