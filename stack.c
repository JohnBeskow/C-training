
#include "stack.h"
#include <assert.h>
#include "list.h"

/*
 	vi använder oss *endast* av list-interfacet
	för att skriva interagera med listan i bakgrunden
*/

Stack createStack(void){
	return createEmptyList(); //är korrekt, ändra inte
}

int isStackEmpty(const Stack s){
	return isEmpty(s);
}

int push(Stack* s, const Data d){
    return addFirst(s, d);
	//Postcondition: d ligger överst på stacken (testa med assert) pd: testa inte med assert

}

Data pop(Stack* s){
    assert(!isEmpty(*s));

    Data d = getFirstElement(*s);
    removeFirst(s);
    return d;
	//Precondition: stacken får inte vara tom (testa med assert)

}

Data peekStack(const Stack s){
    assert(!isEmpty(s));
    return getFirstElement(s);
	//Precondition: stacken får inte vara tom (testa med assert)

}

void clearStack(Stack* s){
    clearList(s);
    assert(!isEmpty(*s));
	//Postcondition: stacken är tom (testa med assert)
}

//kan vara bra att i utskriften skriva ut vad som är överst!
void printStack(const Stack s, FILE* stream){
    fprintf(stream, "Top is Left\n");
    printList(s, stream);
}
