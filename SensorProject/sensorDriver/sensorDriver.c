#include "sensorDriver.h"

STATUS installDrv()
{
	if (driverNumber != -1)
	{
		return ERROR;
	}		
	
	if ((semDeviceList = semBCreate(SEM_Q_FIFO, SEM_FULL)) == NULL)
	{
		return ERROR;
	}
	
	// TODO : Créer sémaphore pour accès à la liste chainée.
	driverNumber = iosDrvInstall(0, 0, sensorOpen, sensorClose, sensorRead, 0, sensorIoctl);
	return OK;	
}

STATUS uninstallDrv()
{
	int canUninstall = true;
	int drvNumber = driverNumber;
	SENSOR_DEV_ELT** currentPosition;	
	SENSOR_DEV_ELT** previousPosition;
	
	if (drvNumber == -1)
	{
		return ERROR;
	}
	
	semTake(semDeviceList, WAIT_FOREVER);
	
	// Make sure that no device is in use.
	currentPosition = &deviceList;
	while (*currentPosition != NULL)
	{
		if ((*currentPosition)->sensorDev->openCount > 0)
		{
			canUninstall = false;
		}
		currentPosition = &((SENSOR_DEV_ELT*)((*currentPosition)->nextElt));
	}
	
	if (!canUninstall)
	{
		semGive(semDeviceList);
		return ERROR;
	}
	
	// Free the deviceList.
	currentPosition = &deviceList;
	previousPosition = NULL;
	while (*currentPosition != NULL)
	{
		previousPosition = currentPosition;
		currentPosition = &((SENSOR_DEV_ELT*)((*currentPosition)->nextElt));
		
		free(*previousPosition);
		*previousPosition = NULL;
	}
	
	semGive(semDeviceList);
	
	// Delete the semaphore protecting the deviceList.
	if(semDeviceList != NULL)
	{
		semDelete(semDeviceList);
	}
	
	// Remove the driver.
	driverNumber = -1;
	return iosDrvRemove(drvNumber, true);	
}

STATUS addDev(char* devName, char* sensorId)
{
	SENSOR_DEV *p;
	char *pNameTail;
	STATUS status;
	SENSOR_DEV_ELT** insertPosition;
	SENSOR_DEV_ELT* elt;
	
	if (driverNumber == -1)
	{
		return ERROR;
	}
	
	p = (SENSOR_DEV*)iosDevFind(devName, &pNameTail);
	if (p != NULL && pNameTail[0] == 0)
	{
		return ERROR;
	}		
	
	p = (SENSOR_DEV*)malloc(sizeof(SENSOR_DEV));
	
	p->openCount = 0;
	p->lastReadValue.id = -1;	
	strcpy(p->sensorId, sensorId);
	
	status = iosDevAdd((DEV_HDR*)p, devName, driverNumber);
	
	if (status == OK)
	{
		semTake(semDeviceList, WAIT_FOREVER);
		
		insertPosition = &deviceList;
		while (*insertPosition != NULL)
		{
			insertPosition = &((SENSOR_DEV_ELT*)((*insertPosition)->nextElt));
		}
		
		elt = (SENSOR_DEV_ELT*)malloc(sizeof(SENSOR_DEV_ELT));
		elt->sensorDev = p;
		elt->nextElt = NULL;
		*insertPosition = elt;
		
		semGive(semDeviceList);
	}
	
	return status;
}

STATUS removeDev(char* devName)
{
	SENSOR_DEV *p;
	char *pNameTail;
	STATUS status;
	SENSOR_DEV_ELT** currentPosition;
	SENSOR_DEV_ELT* previousSensorDev;
		
	if (driverNumber == -1)
	{
		return ERROR;
	}
	
	p = (SENSOR_DEV*)iosDevFind(devName, &pNameTail);
	if (p == NULL || pNameTail[0] != 0) // TODO: Check the condition.
	{
		return ERROR;
	}	
	
	if (p->openCount > 0)
	{
		return ERROR;
	}
		
	iosDevDelete((DEV_HDR*)p);
	
	semTake(semDeviceList, WAIT_FOREVER);
	
	currentPosition = &deviceList;
	
	while (*currentPosition != NULL && (*currentPosition)->sensorDev != p)
	{
		currentPosition = &((SENSOR_DEV_ELT*)((*currentPosition)->nextElt));
	}
	
	if (*currentPosition != NULL)
	{
		previousSensorDev = *currentPosition;
		if (currentPosition != NULL)
		{
			*currentPosition = (SENSOR_DEV_ELT*)((*currentPosition)->nextElt);			
		}
		
		free(previousSensorDev);
	}
	
	semGive(semDeviceList);
	
	free(p);
	
	return OK;
}

STATUS sensorOpen(SENSOR_DEV *p, char* pNameTail, int flag)
{
	if (pNameTail[0] != 0) // TODO: Check condition.
	{
		return ERROR;
	}
	p->openCount++;
	return (int)p;	
}

STATUS sensorClose(SENSOR_DEV *p)
{
	if (p->openCount > 0)
	{
		p->openCount--;
	}	
	
	return OK;
}

STATUS sensorRead(SENSOR_DEV *p, char *buff, int nBytes)
{
	int i;
	int position = 0;
	char* messageIdBytes = ((char*)&(p->lastReadValue.id));
	char* messageTimestampBytes = ((char*)&(p->lastReadValue.timevalue));
	
	if (nBytes < (ID_SIZE + TIME_SIZE + VALUE_SIZE))
	{
		return ERROR;
	}
	
	if (p->lastReadValue.id < 0)
	{
		return ERROR;
	}
	
	for (i = 0; i < ID_SIZE; i++)
	{
		buff[position] = messageIdBytes[i];
		position++;
	}
	
	for (i = 0; i < TIME_SIZE; i++)
	{
		buff[position] = messageTimestampBytes[i];
		position++;
	}
	
	for (i = 0; i < VALUE_SIZE; i++)
	{
		buff[position] = p->lastReadValue.value[i];
		position++;
	}
	
	return position;
}

STATUS sensorIoctl(SENSOR_DEV *p, int fonction, int arg)
{
	
}

void receiveSensorInterrupt()
{
	struct timespec tp;
	char sensorIdBytes[2];
	char sensorValueBytes[2];
	SENSOR_DEV* currentSensorDev = NULL;
	SENSOR_DEV_ELT** currentPosition = &deviceList;
		
	sensorIdBytes[0] = sensorData[0];
	sensorIdBytes[1] = sensorData[1];
	
	if (semTake(semDeviceList, NO_WAIT) == ERROR)
	{
		return;
	}
	
	while (*currentPosition != NULL)
	{
		if ((int)(*((*currentPosition)->sensorDev->sensorId)) == (int)(*sensorIdBytes))
		{
			currentSensorDev = (*currentPosition)->sensorDev;
		}
		
		currentPosition = &((SENSOR_DEV_ELT*)((*currentPosition)->nextElt));
	}
	
	semGive(semDeviceList);
	
	if (currentSensorDev != NULL)
	{		
		if (clock_gettime(CLOCK_REALTIME, &tp) < 0)
		{
			return;
		}
		
		sensorValueBytes[0] = sensorData[2];
		sensorValueBytes[1] = sensorData[3];
		
		strcpy(currentSensorDev->lastReadValue.value, sensorValueBytes);
		currentSensorDev->lastReadValue.id++;
		currentSensorDev->lastReadValue.timevalue = tp.tv_sec;			
	}
}
