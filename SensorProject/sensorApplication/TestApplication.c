#include "TestApplication.h"

int initTestApp()
{
	int sensor1Id = 1;
	int sensor2Id = 2;
	
	// Install the driver.
	printf("\nInstalling driver: %d\n\n", installDrv());
	
	// Add two devices, sensor1 & sensor2.
	printf("Adding sensor with id '1': %d\n", addDev("/sensor1", ((char*)&sensor1Id)));
	printf("Adding sensor with id '2': %d\n", addDev("/sensor2", ((char*)&sensor2Id)));
}

int useTestApp()
{
	int sensor1;
	int sensor2;
	
	char buffer1[10];
	char buffer2[10];
	
	int nb1;
	int nb2;
	
	// Open sensor1.
	sensor1 = open("/sensor1", 0, 0);
	if (sensor1 < 0)
	{
		printf("\nCouldn't open sensor 1.\n");
		return ERROR;
	}
	
	printf("\nOpened sensor1.\n");
	
	// Open sensor2.
	sensor2 = open("/sensor2", 0, 0);
	if (sensor2 < 0)
	{
		printf("Couldn't open sensor 2.\n");
		return ERROR;
	}
	
	printf("Opened sensor2.\n\n");
	
	// Read the value from sensor1.
	nb1 = read(sensor1, buffer1, 10);		
	if (nb1 >= 0)
	{
		printf("Resultat 1 :\n");
		
		// Id
		printf("Id: ");
		printf("%d\n", CharToInt(buffer1));
		
		// Time
		printf("Time: ");
		printf("%d\n", CharToLong(buffer1 + ID_SIZE));
		
		// Value
		printf("Value: ");
		printf("%d\n\n", CharToValue(buffer1 + ID_SIZE + TIME_SIZE));
	}
	else
	{
		printf("Nothing to read on sensor 1.\n\n");
	}
	
	// Read the value from sensor2.
	nb2 = read(sensor2, buffer2, 10);		
	if (nb2 >= 0)
	{
		printf("Resultat 2 :\n");
		
		// Id
		printf("Id: ");
		printf("%d\n", CharToInt(buffer2));
		
		// Time
		printf("Time: ");
		printf("%d\n", CharToLong(buffer2 + ID_SIZE));
		
		// Value
		printf("Value: ");
		printf("%d\n\n", CharToValue(buffer2 + ID_SIZE + TIME_SIZE));
	}
	else
	{
		printf("Nothing to read on sensor 2.\n\n");
	}
	
	// Close sensor1.
	printf("Closing sensor1: %d\n", close(sensor1));
	
	// Close sensor2.
	printf("Closing sensor2: %d\n\n", close(sensor2));
	
	return OK;
}

int destroyTestApp()
{
	// Remove the devices.
	printf("\nRemoving sensor with id '1': %d\n", removeDev("/sensor1"));
	printf("Removing sensor with id '2': %d\n\n", removeDev("/sensor2"));
	
	// Uninstall the driver.
	printf("Uninstalling driver: %d\n", uninstallDrv());
}

long CharToLong(char* src)
{
	long dest;
	memcpy(&dest, src, sizeof(dest));
	return dest;
}

int CharToInt(char* src)
{
	int dest;
	memcpy(&dest, src, sizeof(dest));
	return dest;
}

int CharToValue(char* src)
{
	int dest;
	memcpy(&dest, src, 2);
	return dest;
}
