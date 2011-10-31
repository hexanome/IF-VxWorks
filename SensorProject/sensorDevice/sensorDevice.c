#include "sensorDevice.h"

int initSensor()
{
	if ((semSensorData = semBCreate(SEM_Q_FIFO, SEM_FULL)) == NULL)
	{
		return ERROR;
	}
	return OK;
}

void killSensor()
{
	if(semSensorData != NULL)
	{
		semDelete(semSensorData);
	}			
}

int sensorSendMessage(int sensorId, int sensorValue)
{
	int i = 0;
	char* sensorIdBytes = ((char*)&sensorId);
	char* sensorValueBytes = ((char*)&sensorValue);
	
	semTake(semSensorData, WAIT_FOREVER);
		
	sensorData[0] = sensorIdBytes[0];
	sensorData[1] = sensorIdBytes[1];
	sensorData[2] = sensorValueBytes[0];
	sensorData[3] = sensorValueBytes[1];

	receiveSensorInterrupt();
	
	semGive(semSensorData);	
	
	return OK;
}

void sensorStartMessages(int sensorId, int interval)
{
	continueTask = 1;
	sp(sensorSendMessagesTask, sensorId, interval, 0, 0, 0, 0, 0, 0, 0);
}

void sensorStopMessages()
{
	continueTask = 0;
}

int sensorSendMessagesTask(int sensorId, int interval)
{
	while (continueTask)
	{
		sensorSendMessage(sensorId, (rand() % 100));
		taskDelay(sysClkRateGet() * interval);
	}
}
