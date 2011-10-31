#ifndef __TEST_APPLICATION_H__
#define __TEST_APPLICATION_H__

#include "../sensorDriver/sensorDriver.h"

// Application wich is using the device.

int initTestApp();
int useTestApp();
int destroyTestApp();

int testApp ();
long CharToLong(char * src);
int CharToInt(char * src);
int CharToValue(char* src);

#endif
