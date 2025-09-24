#include "../Includes/preprocessor.h"
#include "../Includes/infometers.h"
#include "../Includes/hud.h"

extern pthread_mutex_t varMtx;
extern pthread_mutex_t stackMtx;
extern pthread_mutex_t queueMtx;
extern pthread_mutex_t listMtx;

extern serverState* state;

void pushLog(char* log){
	
	char buff[LOGMSGLENGTH]={0};
	strncpy(buff,log,LOGMSGLENGTH);
/*	printf("pointer do mutex: %p\n",&listMtx);
	acessQueueMtx(&listMtx,state->logs,buff,0);
*/
}

void* graphicsLoop(void* params){


while(acessVarMtx(&varMtx,&state->serverRunning,0,-1)){

	printServerState();
}

return params;
}

void* serverLogWritting(void* params){


while(acessVarMtx(&varMtx,&state->serverRunning,0,-1)){

	printServerLogs();
}

return params;
}

void* updateRates(void* arg){

	while(acessVarMtx(&varMtx,&state->serverRunning,0,-1)){
		u_int64_t currSent=acessVarMtx(&varMtx,&state->totalSent,0,-1);
		struct timeval start, end;
		gettimeofday(&start,NULL);
		gettimeofday(&end,NULL);
		usleep(100000);
		u_int64_t afterSent=acessVarMtx(&varMtx,&state->totalSent,0,-1);
		double byteSendingRate=((double)afterSent-(double)currSent)/((double)end.tv_sec-(double)start.tv_sec);
		acessVarMtxDouble(&varMtx,&state->trafficRate,byteSendingRate,0);

	}
	
	pushLog("Updater de info a sair!!!");
	return arg;

}
