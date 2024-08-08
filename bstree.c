#include <stdlib.h>
#include "BSTree.h"

#include <math.h> //log2
#include <assert.h>

// HJÄLPFUNKTIONER


// Skapar en trädnod, initierar och returnerar den ifall allokeringen lyckades
static struct treeNode* createNode(int data)
{
    struct treeNode* t = (struct treeNode*)malloc(sizeof(struct treeNode));
    if(t){
        t->nodeValue = data;
        t->left = NULL;
        t->right = NULL;
    }

	return t; //fixa
}

// Hjälpfunktion till treeToArray()
// Kopierar elementen från trädet till arrayen i sorterad ordning
// 'index' är var nästa element från trädet ska sitta i arrayen
// Returnerar platsen som nästa element ska sitta på
static int nodesToArray(const BSTree tree, int* array, int index) {
	return 0; //fixa
}

// Returnerar det största värdet av a och b
static int nodesToArray(const BSTree tree, int* array, int index)
{
    if (tree == NULL)
        return index;

    index = nodesToArray(tree->left, array, index);
    array[index++] = tree->nodeValue;
    index = nodesToArray(tree->right, array, index);

    return index;
}


// Returnerar det minsta värdet i ett träd
static int findLowest(const BSTree tree)
{
    assert(!isEmpty(tree));

    while (tree->left != NULL)
        tree = tree->left;

    return tree->nodeValue;
}


// Hjälpfunktion till arrayToTree()
// Bygger upp ett sorterat balanserat träd från en sorterad array
static void buildTreeFromArray(BSTree* tree, const int arr[], int size)
{
    if (size <= 0)
        return;

    int mid = size / 2;
    *tree = createNode(arr[mid]);

    buildTreeFromArray(&(*tree)->left, arr, mid);
    buildTreeFromArray(&(*tree)->right, arr + mid + 1, size - mid - 1);
}



// INTERFACE


// Skapar ett tomt träd
BSTree emptyTree(void)
{
	return NULL; // funktionen är färdig, ändra inte
}

// Returnerar 1 ifall trädet är tomt, 0 annars
int isEmpty(const BSTree tree)
{
    if(tree == NULL)
        return 1;
    return 0;
}

// Sätter in 'data' på rätt plats i trädet
int insertSorted(BSTree* tree, const int data)
{
    if (isEmpty(*tree)) {
        *tree = createNode(data);
        return !isEmpty(*tree);
    }
    if (data < (*tree)->nodeValue)
        return insertSorted(&(*tree)->left, data);
    if (data > (*tree)->nodeValue)
        return insertSorted(&(*tree)->right, data);

    return 0; // Data already exists
}


void printPreorder(const BSTree tree, FILE* stream)
{
    if(!isEmpty(tree)){
        fprintf(stream, "%d ", tree->nodeValue);
        printPreorder(tree->left, stream);
        printPreorder(tree->right, stream);
    }

}

void printInorder(const BSTree tree, FILE* stream)
{
    if(!isEmpty(tree)){
        printInorder(tree->left, stream);
        fprintf(stream, "%d ", tree->nodeValue);
        printInorder(tree->right, stream);
}
}
void printPostorder(const BSTree tree, FILE* stream)
{
    if(!isEmpty(tree)){
        printPostorder(tree->left, stream);
        printPostorder(tree->right, stream);
        fprintf(stream, "%d ", tree->nodeValue);
}
}
// svår, optional
// skriver ut trädet brädden först
void printLevelorder(const BSTree tree, FILE* stream) {


}

// Returnerar 1 om 'data' finns i tree, 0 annars
int find(const BSTree tree, const int data)
{
    if(isEmpty(tree)){
        return 0;
    }
    if(data < tree->nodeValue)
        return find(tree->left, data);
    if(data > tree->nodeValue)
        return find(tree->right, data);

	return 1; //fixa

}

// Tar bort 'data' från trädet om det finns
void removeElement(BSTree* tree, const int data)
{

	// Postcondition: 'data' finns inte i trädet
	// Postconditionet förutsätter att trädet förbjuder dubbletter
}

// Returnerar hur många noder som totalt finns i trädet
int numberOfNodes(const BSTree tree)
{
    if (isEmpty(tree))
        return 0;
    return 1 + numberOfNodes(tree->left) + numberOfNodes(tree->right);
}


// Returnerar hur djupt trädet är
int depth(const BSTree tree)
{
    if (isEmpty(tree))
        return 0;
    return 1 + max(depth(tree->left), depth(tree->right));
}


// Returnerar minimidjupet för trädet
int minDepth(const BSTree tree)
{
    return (int)ceil(log2((double)numberOfNodes(tree) + 1));
}


// Returnerar en dynamiskt allokerad array som innehåller trädets data sorterat
// 'size' ska innehålla arrayens storlek när funktionen är klar
int* treeToArray(const BSTree tree, int* size)
{
    *size = numberOfNodes(tree);
    int* array = (int*)malloc(*size * sizeof(int));
    if (array != NULL) {
        nodesToArray(tree, array, 0);
    }
    return array;
}


// Returnerar ett sorterat balancerat träd från en sorterad array
BSTree* arrayToTree(const int arr[], const int size)
{
    BSTree* tree = (BSTree*)malloc(sizeof(BSTree));
    if (tree != NULL) {
        *tree = NULL;
        buildTreeFromArray(tree, arr, size);
    }
    return tree;
}


// Balanserar trädet så att depth(tree) == minDepth(tree)
BSTree* arrayToTree(const int arr[], const int size)
{
    BSTree* tree = (BSTree*)malloc(sizeof(BSTree));
    if (tree != NULL) {
        *tree = NULL;
        buildTreeFromArray(tree, arr, size);
    }
    return tree;
}


// Mappar trädet
void mapTree(BSTree* tree, int (*f)(int))
{
    if (!isEmpty(*tree)) {
        (*tree)->nodeValue = f((*tree)->nodeValue);
        mapTree(&(*tree)->left, f);
        mapTree(&(*tree)->right, f);
    }
}


// Frigör minne för trädet och gör det tomt
void freeTree(BSTree* tree)
{
    if (!isEmpty(*tree)) {
        freeTree(&(*tree)->left);
        freeTree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}

