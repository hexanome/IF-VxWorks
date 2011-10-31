#ifndef __SENSOR_DEVICE_H__
#define __SENSOR_DEVICE_H__

#include <vxworks.h>
#include <taskLib.h>
#include <semLib.h>
#include <stdio.h>
#include <usrLib.h>
#include <sysLib.h>
#include "../sensorDriver/sensorDriver.h"

SEM_ID semSensorData; // protection semaphore for the sensorData ressource.
char sensorData[4]; // shared ressource for the driver/device communication.
static int continueTask;

int initSensor();
void killSensor();
int sensorSendMessage(int sensorId, int sensorValue);
void sensorStartMessages(int sensorId, int interval);
void sensorStopMessages();
int sensorSendMessagesTask(int sensorId, int interval);

#endif
