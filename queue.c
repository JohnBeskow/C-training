#include "queue.h"
#include <assert.h>
#include <stdio.h>

/*
	vi anv�nder oss *endast* av list-interfacet
	f�r att skriva interagera med listan i bakgrunden
*/

Queue createQueue(void) {
	return createEmptyList(); //�r korrekt, �ndra inte
}

int isQueueEmpty(const Queue q) {
	return isEmpty(q);
}

int enqueue(Queue* q, const Data d) {
	return addLast(q, d);
	//Postcondition: d ligger l�ngst bak i k�n (testa INTE med assert)
}

Data dequeue(Queue* q) {
	//Precondition: k�n f�r inte vara tom (testa med assert)
	assert(!isQueueEmpty(*q));

	Data d = getFirstElement(*q);
	removeFirst(q);
	return d;
}

Data peekQueue(const Queue q) {
	//Precondition: k�n f�r inte vara tom (testa med assert)
	assert(!isQueueEmpty(q));

	return getFirstElement(q);
}


void clearQueue(Queue* q) {
	clearList(q);
	//Postcondition: stacken �r tom (testa med assert)
	assert(isQueueEmpty(*q));
}

//kan vara bra att i utskriften skriva ut vad som �r l�ngst fram!
void printQueue(const Queue q, FILE* stream) {
	fprintf(stream, "Left is first\n");
	printList(q, stream);
}