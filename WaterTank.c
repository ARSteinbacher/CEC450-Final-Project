#include <vxWorks.h> 
#include <stdio.h> 
#include <taskLib.h> 
#include <sysLib.h> 
#include <msgQLib.h> 
#include <timers.h>

#define maxW_Level 50.0;
#define criticalPressure 50;
#define maxPressure;
#define criticalTemp 100;
#define minW_Level 15;
#define minTemp 10;
#define minPressure 20;

SEM_ID valveSem;

int waterSensor, tempSensor, pressureSensor, waterTank, user, controlUnit;

void startTasks(void){
	valveSem = semMCreate(SEM_Q_FIFO, SEM_DELETE_SAFE);
	
	controlUnit = taskSpawn("controlUnit", 100, 0x100, 2000, (FUNCPTR)monitor, protect,0,0,0,0,0,0,0,0,0);
	waterSensor = taskSpawn("waterSensor", 100, 0x100, 2000, (FUNCPTR)monitor, protect,0,0,0,0,0,0,0,0,0);
	tempSensor = taskSpawn("tempSensor", 100, 0x100, 2000, (FUNCPTR)monitor, protect,0,0,0,0,0,0,0,0,0);
	pressureSensor = taskSpawn("pressureSensor", 100, 0x100, 2000, (FUNCPTR)monitor, protect,0,0,0,0,0,0,0,0,0);
	waterTank = taskSpawn("waterTank", 100, 0x100, 2000, (FUNCPTR)monitor, protect,0,0,0,0,0,0,0,0,0);
//	user = taskSpawn("user", 100, 0x100, 2000, (FUNCPTR)monitor, protect,0,0,0,0,0,0,0,0,0);
}

