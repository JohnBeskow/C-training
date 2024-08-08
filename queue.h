
#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

typedef List Queue; //En kö är en lista i bakgrunden

//INTERFACE

//skapar och returnerar en ny tom stack
Queue createQueue(void);

//undersöker om en stack är tom
int isQueueEmpty(const Queue q);

//lägger till 'd' längst bak i kön
//returnerar 1 ifall lyckades, annars 0
int enqueue(Queue* q, const Data d);

//tar bort och returnerar elementet längst fram i kön
Data dequeue(Queue* q);

//returnerar elementet högst upp på stacken
Data peekQueue(const Queue q);

//tömmer kön
void clearQueue(Queue* q);

//skriver ut alla element i listan till den angivna strömmen
void printQueue(const Queue q, FILE* stream);

#endif
