#ifndef ATOMICOPS_H
#define ATOMICOPS_H
void* acessListMtx(pthread_mutex_t * mtx,DListW* list,void* value,u_int64_t index,int op);

void* acessListCompMtx(pthread_mutex_t * mtx,DListWComp* list,void* value,u_int64_t index,int op);

void* acessItMtx(pthread_mutex_t * mtx,dliterator* it,int op);

void* acessItCompMtx(pthread_mutex_t * mtx,dliteratorcomp* it,int op);

void* acessStackMtx(pthread_mutex_t * mtx,stackList* stck,void* value,int op);

void* acessQueueMtx(pthread_mutex_t * mtx,queueList* q,void* value,int op);

void* acessVarMtxPtr(pthread_mutex_t * mtx,void** var,void* value,int op);

u_int64_t acessVarMtxUnsigned(pthread_mutex_t * mtx,u_int64_t* var,u_int64_t value,int op);

int64_t acessVarMtx(pthread_mutex_t * mtx,int64_t* var,int64_t value,int op);

int32_t acessVarMtx32(pthread_mutex_t * mtx,int32_t* var,int32_t value,int op);

int16_t acessVarMtx16(pthread_mutex_t * mtx,int16_t* var,int16_t value,int op);

void printScrMtx(pthread_mutex_t * mtx,char* str,int y,int x);

double acessVarMtxDouble(pthread_mutex_t * mtx,double* var,double value,int op);

char* acessVarMtxString(pthread_mutex_t * mtx,char** var,char* value,int op);

#endif
