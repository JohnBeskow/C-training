
#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

typedef List Queue; //En k� �r en lista i bakgrunden

//INTERFACE

//skapar och returnerar en ny tom stack
Queue createQueue(void);

//unders�ker om en stack �r tom
int isQueueEmpty(const Queue q);

//l�gger till 'd' l�ngst bak i k�n
//returnerar 1 ifall lyckades, annars 0
int enqueue(Queue* q, const Data d);

//tar bort och returnerar elementet l�ngst fram i k�n
Data dequeue(Queue* q);

//returnerar elementet h�gst upp p� stacken
Data peekQueue(const Queue q);

//t�mmer k�n
void clearQueue(Queue* q);

//skriver ut alla element i listan till den angivna str�mmen
void printQueue(const Queue q, FILE* stream);

#endif
