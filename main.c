#include "lab12.h"

int main(void){
    PQueue Queue = initPQueue();
    printPQueue(Queue);
    insertPQ(2, 20, Queue);
    printPQueue(Queue);
    insertPQ(4, 40, Queue);
    printPQueue(Queue);
    insertPQ(6, 60, Queue);
    printPQueue(Queue);
    insertPQ(2, 20, Queue);
    printPQueue(Queue);
    insertPQ(3, 30, Queue);
    printPQueue(Queue);
    insertPQ(1, 10, Queue);
    printPQueue(Queue);
    insertPQ(9, 90, Queue);
    printPQueue(Queue);
    insertPQ(150, 150, Queue);
    printPQueue(Queue);
    insertPQ(1, 0, Queue);
    printPQueue(Queue);
    insertPQ(16, 160, Queue);
    printPQueue(Queue);
    printf("Size of queue is: %d\n", Queue.list->numOfItems);
    
    printf("Max Priority node has value of: %.2f\n", (returnMax(Queue))->priority);
    printf("Min Priority node has value of: %.2f\n", (returnMin(Queue))->priority);
    printPQueue(Queue);
    printf("Deleting Max Priority node with value of: %.2f\n", (deleteMax(Queue))->temperature);
    printPQueue(Queue);    
    printf("Deleting Min Priority node with value of: %.2f\n", (deleteMin(Queue))->temperature);
    printPQueue(Queue);    
    freePQueue(Queue);
    printf("Finished main");
    return 0;
}