
#ifndef STACK_H
#define STACK_H
#include "list.h"
#include <stdio.h>

typedef List Stack; 


Stack createStack(void);


int isStackEmpty(const Stack s);


int push(Stack* s, const Data d);


Data pop(Stack* s);


Data peekStack(const Stack s);


void clearStack(Stack* s);


void printStack(const Stack s, FILE* stream);

#endif
