#ifndef SERVER_H
#define SERVER_H


#define LOGMSGLENGTH 100
#define PINGSIZE 50
#define OUTPUTLENGTH 100000
#define MAXTIMEOUTCONSECS 10
#define MAXTIMEOUTCONUSECS 1000000
#define MAXTIMEOUTPING 10
#define MAXTIMEOUTPINGU 1000000
#define MAX_CLIENTS_HARD_LIMIT 1000

typedef struct serverState{
	
	char logBuff[LOGMSGLENGTH*100];
	char addressContainer[INET_ADDRSTRLEN];
	char *pathToFile;
	int64_t serverRunning;
	int64_t idle;
	int64_t adminsActive,clientsActive,maxNumOfClients;
	DListWComp* listOfClients;
	DListWComp* listOfAdmins;
	stackList *kickedClients;
	queueList* logs;
	int server_socket;
	struct sockaddr_in server_address;
	int64_t totalSent;
	int64_t timeActive;
	double trafficRate;
	int64_t dataSize;
	
}serverState;

typedef struct clientStruct{
	pthread_t threadid;
	struct	sockaddr_in clientAddress;
	int client_socket;
	socklen_t addrLength;
	int64_t numOfBytesSent;
	int64_t done;
	int64_t bytesToRead;
	int fd;
	int64_t isAdmin;
	char login[FIELDLENGTH+1];
}clientStruct;

typedef struct command{

	char string[LINESIZE];
	clientStruct* whoItWas;


}command;
void initEverything(u_int16_t port,char* pathToFile,u_int64_t startDataSize,u_int16_t startMaxNumOfClients);

void sigint_handler(int signal);

void cleanup(void);

#endif

