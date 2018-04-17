#include <vxWorks.h> 
#include <stdio.h> 
#include <taskLib.h> 
#include <sysLib.h> 
#include <msgQLib.h> 
#include <timers.h>
#include <WaterTank.h>
#include <time.h>



typedef enum { false, true } bool;

#define TICK sysClkRateGet()/60

void Open_Valve(SEM_ID sem, bool valve){
	
	srand(time(NULL));
	int delayTime;
	
	
	while(1){
		
		delayTime = rand() %60 + 1;
		
		semTake(sem,-1);
		if(!valve){
			valve = true;
			taskDelay(delayTime * TICK);
		}
		
	}
	
}
