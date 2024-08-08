#ifndef BSTREE_H
#define BSTREE_H

struct treeNode
{
	int nodeValue;
	struct treeNode* left;
	struct treeNode* right;
};

typedef struct treeNode* BSTree;

// Skapar ett tomt träd
BSTree emptyTree(void);

// Returnerar 1 ifall trädet är tomt, 0 annars
int isEmpty(const BSTree tree);

// Sätter in 'data' sorterat i *tree
int insertSorted(BSTree* tree, const int data);

// Utskriftsfunktioner
void printPreorder(const BSTree tree, FILE* stream);
void printInorder(const BSTree tree, FILE* stream);
void printPostorder(const BSTree tree, FILE* stream);

// Svår utskriftsfunktion
void printLevelorder(const BSTree tree, FILE* stream);

// Returnerar 1 om 'data' finns i tree, 0 annars
int find(const BSTree tree, const int data);

// Tar bort 'data' från trädet om det finns
void removeElement(BSTree* tree, const int data);

// Returnerar hur många noder som totalt finns i trädet
int numberOfNodes(const BSTree tree);

// Returnerar hur djupt trädet är
int depth(const BSTree tree);

// Returnerar minimidjupet för trädet
int minDepth(const BSTree tree);

// Returnerar en dynamiskt allokerad array som innehåller trädets data sorterat
// 'size' ska innehålla arrayens storlek när funktionen är klar
int* treeToArray(const BSTree tree, int* size);

// Returnerar ett sorterat balancerat träd från en sorterad array
BSTree* arrayToTree(const int arr[], const int size);

// Balanserar trädet så att depth(tree) == minDepth(tree)
void balanceTree(BSTree* tree);

// Mappar trädet
void mapTree(BSTree* tree, int (*f)(int));

// Frigör minne för trädet och gör det tomt
void freeTree(BSTree* tree);

#endif
