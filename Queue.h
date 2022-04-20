#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


struct Queue{
    struct Customer *head;
    int count;
    int maxSize;
    int servedCustomers;
    int returnedCustomers;
    int timeOfSimulation;
};

struct Customer{
    struct Customer* next;
    int timeLimit;
};

struct Queue *initQueue(int size, int time);
void pushBack(struct Queue *q);
void popOut(struct Queue *q);
void printQueue(struct Queue *q);
void manualSimulation();
void fileSimulation(const char* fname);
void startSimulation(int timeOfSimulation, int maxLength);
void printQueueStats(struct Queue *q);
void deletingQueue(struct Queue *q);





#endif