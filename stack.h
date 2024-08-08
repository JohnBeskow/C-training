
#ifndef STACK_H
#define STACK_H
#include "list.h"
#include <stdio.h>

typedef List Stack; //En stack är en lista i bakgrunden

//INTERFACE

//skapar och returnerar en ny tom stack
Stack createStack(void);

//undersöker om en stack är tom
int isStackEmpty(const Stack s);

//lägger till 'd' högst upp på stacken
//returnerar 1 ifall lyckades, annars 0
int push(Stack* s, const Data d);

//tar bort och returnerar värdet högst upp på stacken
Data pop(Stack* s);

//returnerar elementet högst upp på stacken
Data peekStack(const Stack s);

//tömmer stacken
void clearStack(Stack* s);

//skriver ut alla element i listan till den angivna strömmen
void printStack(const Stack s, FILE* stream);

#endif
