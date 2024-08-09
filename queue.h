
#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

typedef List Queue; 


Queue createQueue(void);

int isQueueEmpty(const Queue q);

int enqueue(Queue* q, const Data d);

Data dequeue(Queue* q);

Data peekQueue(const Queue q);

void clearQueue(Queue* q);

void printQueue(const Queue q, FILE* stream);

#endif
