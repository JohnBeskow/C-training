#include "queue.h"
#include <assert.h>
#include <stdio.h>


Queue createQueue(void) {
	return createEmptyList(); 
}

int isQueueEmpty(const Queue q) {
	return isEmpty(q);
}

int enqueue(Queue* q, const Data d) {
	return addLast(q, d);
}

Data dequeue(Queue* q) {
	assert(!isQueueEmpty(*q));

	Data d = getFirstElement(*q);
	removeFirst(q);
	return d;
}

Data peekQueue(const Queue q) {
	assert(!isQueueEmpty(q));

	return getFirstElement(q);
}


void clearQueue(Queue* q) {
	clearList(q);
	assert(isQueueEmpty(*q));
}

void printQueue(const Queue q, FILE* stream) {
	fprintf(stream, "Left is first\n");
	printList(q, stream);
}