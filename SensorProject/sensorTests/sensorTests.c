#include "sensorTests.h"

void startTests()
{
	int sensorId1 = 1;
	int sensor1;

	int totalSuccessCount = 0;
	int totalAdminSuccessCount = 0;
	int totalInstallDrvSuccessCount = 0;
	int totalUninstallDrvSuccessCount = 0;
	// Unit tests on the Admin interface.
	printf("\nStarting tests...\n");
	
	// installDrv
	printf("\nTests on 'installDrv'\n");
	
	printf("\n- Test 1:\n\tFirst driver install\n\t")
	if (installDrv() == OK)
	{
		totalInstallDrvSuccessCount++;
		printf("Returned OK - Success\n");
	}
	else
	{
		prinft("Returned ERROR - Failure\n");
	}
	
	printf("\n- Test 2:\n\Second driver install\n\t")
	if (installDrv() == ERROR)
	{
		totalInstallDrvSuccessCount++;
		printf("Returned ERROR - Success\n");
	}
	else
	{
		prinft("Returned OK - Failure\n");
	}
	
	// Cleaning
	uninstallDrv();
	
	// installDrv - Summary
	printf("\nSummary - 'installDrv' passed %d test(s) out of 2.\n");
	totalAdminSuccessCount += totalInstallDrvSuccessCount;
	
	// uninstallDrv
	printf("\nTests on 'uninstallDrv'\n");
	
	printf("\n- Test 1:\n\tTry to uninstall with no driver installed\n\t")
	if (uninstallDrv() == ERROR)
	{
		totalUninstallDrvSuccessCount++;
		printf("Returned ERROR - Success\n");
	}
	else
	{
		prinft("Returned OK - Failure\n");
	}
	
	// Preparing
	installDrv();
	
	printf("\n- Test 2:\n\tTry to uninstall with driver installed and no devices\n\t")
	if (uninstallDrv() == OK)
	{
		totalUninstallDrvSuccessCount++;
		printf("Returned OK - Success\n");
	}
	else
	{
		prinft("Returned ERROR - Failure\n");
	}
	
	// Preparing
	installDrv();
	addDev("/sensor1", ((char*)&sensorId1));
	
	printf("\n- Test 3:\n\tTry to uninstall with driver installed and 1 device installed\n\t")
	if (uninstallDrv() == OK)
	{
		totalUninstallDrvSuccessCount++;
		printf("Returned OK - Success\n");
	}
	else
	{
		prinft("Returned ERROR - Failure\n");
	}
	
	// Preparing
	installDrv();
	addDev("/sensor1", ((char*)&sensorId1));
	sensor1 = open("/sensor1", 0, 0);
	
	printf("\n- Test 4:\n\tTry to uninstall with driver installed and 1 device installed and opened\n\t")
	if (uninstallDrv() == ERROR)
	{
		totalUninstallDrvSuccessCount++;
		printf("Returned ERROR - Success\n");
	}
	else
	{
		prinft("Returned OK - Failure\n");
	}
	
	// Cleaning
	close(sensor1);
	uninstallDrv();
	
	// uninstallDrv - Summary
	printf("\nSummary - 'uninstallDrv' passed %d test(s) out of 4.\n");
	totalAdminSuccessCount += totalUninstallDrvSuccessCount;
}