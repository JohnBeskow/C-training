#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


static struct node* createListNode(const Data d) {
	struct node* n = (struct node*) malloc(sizeof(struct node));
	if (n) {
		n->d = d;
		n->rest = NULL;
	}
	return n;
}


List createEmptyList(void) {
	return NULL; 
}

int isEmpty(const List l) {
	if (l == NULL)
		return 1;
	return 0;
}

int addFirst(List* l, const Data d) {
	struct node* n = createListNode(d);
	if (n) {
		n->rest = *l;
		*l = n;
		return 1;
	}
	return 0;
}

int addLast(List* l, const Data d) {
	if (isEmpty(*l))
		return addFirst(l, d);
	else
		return addLast(&(*l)->rest, d);
}

void removeFirst(List* l) {
	assert(!isEmpty(*l));

	struct node* toRemove = *l;
	*l = (*l)->rest;
	free(toRemove);
}

void removeLast(List* l) {
	assert(!isEmpty(*l));

	if (isEmpty((*l)->rest))
		removeFirst(l);
	else
		removeLast(&(*l)->rest);
}




int lengthOfList(const List l) {
	if (isEmpty(l))
		return 0;
	else
		return 1 + lengthOfList(l->rest);
}

void clearList(List* l) {
	if (isEmpty(*l))
		return;
	removeFirst(l);
	clearList(l);
	assert(isEmpty(*l));
}

Data getFirstElement(const List l) {
	assert(!isEmpty(l));
	return l->d;
}

Data getLastElement(const List l) {
	assert(!isEmpty(l));

	if (isEmpty(l->rest))
		return l->d;
	return getLastElement(l->rest);
}

//mappar listan
void mapList(const List l, Data(*f) (Data)) {
	if (!isEmpty(l)) {
		l->d = (*f)(l->d);
		mapList(l->rest, f);
	}
}

void printList(const List l, FILE* stream){
    if (isEmpty(l)){
        fprintf(stream, "\n\n");
    }
    else{
        fprintf(stream, " -> (ID: %d | Weight: %d) ", l->d.id, l->d.weight);
        printList(l->rest, stream);
    }


}

//rightfoldar listan
Data foldList(const List l, Data(*f) (Data, Data)) {
	if (isEmpty(l->rest->rest))
		return (*f) (l->d, l->rest->d);
	else
		return (*f) (l->d, foldList(l->rest, f));
}
