#include "lab12.h"

/*This function creates and returns an empty priority queue*/
PQueue initPQueue()
{
	PQueue p;
	p.list = malloc(sizeof(WeatherList));
	if(!p.list){
		printf("***Error: Memory could not be allocated***\n");
		return(p);
	}
	p.list->head = p.list->tail = NULL;
	p.list->numOfItems = 0;
	return(p);
}

/*This function allocates memory for a Weather struct whose priority
value is equal to the first float passed, and the temperature value
equal to the second float passed*/
Weather* createNode(float priority, float temperature)
{
	Weather *new = malloc(sizeof(Weather));
	if(!new){
		printf("***Error: Memory could not be allocated***\n");
		return(NULL);
	}
	new->temperature = temperature;
	new->priority = priority;
	new->previous = NULL; new->next = NULL;
	return(new);
}

/*This function creates a Weather struct with member 'priority' equals to the first input
value, and the member 'temperature' equals to the second input value. The new struct
is placed in the queue in descending order according to its priority value. The function returns
1 if the insertion succeeds or -1 if the insertion fails.*/
int insertPQ(float priority, float temperature,PQueue p)
{
	if(!p.list){
		printf("***Error: Queue is NULL***\n");
		return(-1);
	}
	Weather *new = createNode(priority, temperature);
	if(!new){
		return(-1);
	}
	if(!p.list->head){
		p.list->head = p.list->tail = new;
		p.list->head->next = p.list->tail;
		p.list->tail->next = NULL;
		p.list->tail->previous = p.list->head;
		p.list->head->previous = NULL;
		p.list->numOfItems++;
		return(1);
	}
	if(new->priority > p.list->head->priority){
		new->next = p.list->head;
		p.list->head = new;
		p.list->numOfItems++;
		return(1);
	}
	if(new->priority < p.list->tail->priority){
		new->previous = p.list->tail;
		p.list->tail = new;
		p.list->tail->next = NULL;
		p.list->numOfItems++;
		return(1);
	}
	Weather *temp = p.list->head;
	while(new->priority < temp->priority && temp){
		if(!temp->next){
			p.list->tail->next = new;
			p.list->tail = new;
			p.list->tail->previous = temp;
			p.list->numOfItems++;
			return(1);
		}
		temp = temp->next;
	}
	return(1);
}

/*This function returns but does not delete the minimum priority Weather struct*/
Weather* returnMin(PQueue p)
{
	if(!p.list){
		printf("***Error: Queue is NULL***\n");
		return(NULL);
	}
	if(!p.list->head){
		printf("***Error: Queue is empty***\n");
		return(NULL);
	}
	return(p.list->tail);
}

/*This function returns but does not delete the maximum priority Weather struct*/
Weather* returnMax(PQueue p)
{
	if(!p.list){
		printf("***Error: Queue is NULL***\n");
		return(NULL);
	}
	if(!p.list->head){
		printf("***Error: Queue is empty***\n");
		return(NULL);
	}
	return(p.list->head);
}

/*This function removes the lowest priority Weather struct from the queue
and passes a pointer to it back to the user*/
Weather* deleteMin(PQueue p)
{
	if(!p.list || !p.list->head){
		printf("***Error: Queue is NULL***\n");
		return(NULL);
	}
	Weather *temp = p.list->tail;
	p.list->tail = p.list->tail->previous;
	return(temp);
}

/*This function removes the highest priority Weather struct from the queue
and returns a pointer to it back to the user*/
Weather* deleteMax(PQueue p)
{
	if(!p.list || !p.list->head){
		printf("***Error: Queue is NULL***\n");
		return(NULL);
	}
	Weather *temp = p.list->head;
	p.list->head = p.list->head->next;
	return(temp);
}

/*This function prints all members of the queue from head to tail.
The priority value is listed first, followed by the teperature value enclosed by parenthesis.
These number pairs are separated by an arrow, " --> "*/
void printPQueue(PQueue p)
{
	if(!p.list || !p.list->head){
		printf("***Error: Nothing to print***\n");
		return;
	}
	Weather *temp = p.list->head;
	while(temp){
		printf("%.2f (%.2f) --> ", temp->priority, temp->temperature);
		temp = temp->next;
	}
	printf("End\n");
}

/*This function frees all previously allocated memories, save those removed from the list
via deleteMin or deleteMax. The list is then set to NULL*/
void freePQueue(PQueue p)
{
	if(!p.list){
		printf("***Error: There is no memory to be freed***\n");
		return;
	}
	while(p.list->head){
		Weather *temp = p.list->head;
		free(temp);
		p.list->head = p.list->head->next;
	}
	p.list->head = p.list->tail = NULL;
	p.list->numOfItems = 0;
	free(p.list);
	p.list = NULL;
}









