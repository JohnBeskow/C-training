#include "queue.h"
#include <assert.h>
#include <stdio.h>

/*
	vi använder oss *endast* av list-interfacet
	för att skriva interagera med listan i bakgrunden
*/

Queue createQueue(void) {
	return createEmptyList(); //är korrekt, ändra inte
}

int isQueueEmpty(const Queue q) {
	return isEmpty(q);
}

int enqueue(Queue* q, const Data d) {
	return addLast(q, d);
	//Postcondition: d ligger längst bak i kön (testa INTE med assert)
}

Data dequeue(Queue* q) {
	//Precondition: kön får inte vara tom (testa med assert)
	assert(!isQueueEmpty(*q));

	Data d = getFirstElement(*q);
	removeFirst(q);
	return d;
}

Data peekQueue(const Queue q) {
	//Precondition: kön får inte vara tom (testa med assert)
	assert(!isQueueEmpty(q));

	return getFirstElement(q);
}


void clearQueue(Queue* q) {
	clearList(q);
	//Postcondition: stacken är tom (testa med assert)
	assert(isQueueEmpty(*q));
}

//kan vara bra att i utskriften skriva ut vad som är längst fram!
void printQueue(const Queue q, FILE* stream) {
	fprintf(stream, "Left is first\n");
	printList(q, stream);
}