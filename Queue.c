#include "Queue.h"

void pushBack(struct Queue *q){
    if(q->count==q->maxSize){
        printf("Nie ma miejsca w kolejce\n");
        q->returnedCustomers++;
        return;
    }
    struct Customer *newCustomer = (struct Customer*) malloc(sizeof(struct Customer));
    struct Customer *last; 
    last = q->head;
    q->count++;
    newCustomer->timeLimit = rand()%6+13    ;
    newCustomer->next = NULL;
    if(q->head==NULL){
        q->head=newCustomer;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next = newCustomer;
    printQueue(q);

    return;
}

void popOut(struct Queue *q){
    
    if(q->head!=NULL){
    struct Customer *tmp;
    tmp = q->head;
    q->head = q->head->next;
    printf("kolejny klient obsluzony!\n");
    q->servedCustomers++;
    printQueue(q);
    q->count--;
    free(tmp);

    }
}

void printQueue(struct Queue *q){
    printf("Oto kolejka: ");
    struct Customer *current = q->head;
   	while(current!= NULL){
        printf("%d ", current->timeLimit);
        current = current->next;
    }
    printf("\n");

    
    
}

struct Queue *initQueue(int size, int time){
 
    struct Queue *newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    struct Customer *newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    newQueue->head=newCustomer;
    newCustomer->timeLimit=rand()%6+13;
    newQueue->count = 1;
    newQueue->returnedCustomers = newQueue->servedCustomers = 0;
    newQueue->maxSize=size;
    newQueue->timeOfSimulation=time;
    printQueue(newQueue);
    return newQueue;

}

void manualSimulation(){
    int time, length;
    printf("Witaj w symulacji kolejki\nPodaj ile iteracji ma zostac wykonanych: ");
    scanf("%d",&time);
    printf("Podaj maksymalna dlugosc kolejki: ");
    scanf("%d", &length);
    startSimulation(time,length);
}

void fileSimulation(const char *fname){
    int time, length;
    FILE *fp = fopen(fname,"r");
    if(!fp){
        printf("Nie można otworzyc pliku.");
        exit(EXIT_FAILURE);
    }
    else{
       fscanf(fp,"%d",&time);
       fscanf(fp,"%d",&length);
    }
    fclose(fp);
    startSimulation(time,length);
}

void startSimulation(int timeOfSimulation, int maxLength){
    int processingTime;
    processingTime=0;
    struct Queue *queue = initQueue(maxLength,timeOfSimulation);
    srand(time(0));
    for(int i=0;i<timeOfSimulation;i++){
        int n = rand()%20;
        processingTime++;if(queue->head!=NULL){
        if(processingTime==queue->head->timeLimit){
            popOut(queue);
            processingTime=0;
        }}

        if(n%10==0){
            pushBack(queue);
        }
    }
   printQueueStats(queue);
   deletingQueue(queue);
}

void printQueueStats(struct Queue *q){
    FILE *fp = fopen("queueStats","w");
    fprintf(fp,"Obsluzono %d klientow\n",q->servedCustomers);
    fprintf(fp,"Sredni czas obslugi klienta: %.2f minut\n",(float)q->timeOfSimulation/q->servedCustomers);
    fprintf(fp,"%d zawrocilo z powodu braku miejsca w kolejce\n",q->returnedCustomers);
    fflush(fp);
    fclose(fp);
}

void deletingQueue(struct Queue *q){
    struct Customer* current = q->head;
    struct Customer* next;
 
    while (current != NULL){
       next = current->next;
       free(current);
       current = next;
    }
    q->head = NULL;
    free(q);
    
}


