
#ifndef LIST_H
#define LIST_H

#include <stdio.h>


typedef struct Tuple{
     int id;
     int weight;
}Tuple;

typedef Tuple Data; //ifall vi någonsin vi vill ändra typen av sparat data

struct node {
	Data d;
	struct node* rest; //notera att detta är en lista
};

typedef struct node* List; //nodepointers är listor



//INTERFACE

//skapar och returnerar en ny lista
List createEmptyList(void);

//undersöker om en lista är tom
int isEmpty(const List l);

//lägger till 'd' först i listan
//returnerar 1 ifall lyckades, annars 0
int addFirst(List* l, const Data d);

//lägger till 'd' sist i listan
//returnerar 1 ifall lyckades, annars 0
int addLast(List* l, const Data d);

//tar bort första noden från listan
void removeFirst(List* l);

//tar bort sista noden från listan
void removeLast(List* l);

//returnerar antal element i listan
int lengthOfList(const List l);

//tömmer listan och frigör allt minne
void clearList(List* l);

//skriver ut alla element i listan till den angivna strömmen
void printList(const List l, FILE* stream);

//returnerar värdet på första datat i listan
Data getFirstElement(const List l);

//returnerar värdet på sista datat i listan
Data getLastElement(const List l);

//mappar listan
void mapList(const List l, Data (*f) (Data));

//foldar listan
Data foldList(const List l, Data(*f) (Data, Data));

#endif
