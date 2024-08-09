
#include "stack.h"
#include <assert.h>
#include "list.h"



Stack createStack(void){
	return createEmptyList(); 
}

int isStackEmpty(const Stack s){
	return isEmpty(s);
}

int push(Stack* s, const Data d){
    return addFirst(s, d);


}

Data pop(Stack* s){
    assert(!isEmpty(*s));

    Data d = getFirstElement(*s);
    removeFirst(s);
    return d;

}

Data peekStack(const Stack s){
    assert(!isEmpty(s));
    return getFirstElement(s);
}

void clearStack(Stack* s){
    clearList(s);
    assert(!isEmpty(*s));
}

void printStack(const Stack s, FILE* stream){
    fprintf(stream, "Top is Left\n");
    printList(s, stream);
}
