#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct tempstruct{
    float temperature;
    float priority;
    struct tempstruct *previous, *next;
}Weather;
	
typedef struct linkedlist{
    Weather *head, *tail;
    int numOfItems;
}WeatherList;

typedef struct queuelist{
    WeatherList* list;
}PQueue;

PQueue initPQueue();
Weather* createNode(float,float);
int insertPQ(float,float,PQueue);
Weather* deleteMin(PQueue);
Weather* deleteMax(PQueue);
Weather* returnMin(PQueue); // returns but does not delete
Weather* returnMax(PQueue); // returns but does not delete
void freePQueue(PQueue); // Free all malloced space
void printPQueue(PQueue);
