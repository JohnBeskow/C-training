
#ifndef LIST_H
#define LIST_H

#include <stdio.h>


typedef struct Tuple{
     int id;
     int weight;
}Tuple;

typedef Tuple Data; 

struct node {
	Data d;
	struct node* rest; 
};

typedef struct node* List; 




List createEmptyList(void);

int isEmpty(const List l);

int addFirst(List* l, const Data d);

int addLast(List* l, const Data d);

void removeFirst(List* l);

void removeLast(List* l);

int lengthOfList(const List l);

void clearList(List* l);

void printList(const List l, FILE* stream);

Data getFirstElement(const List l);

Data getLastElement(const List l);

void mapList(const List l, Data (*f) (Data));

Data foldList(const List l, Data(*f) (Data, Data));

#endif
