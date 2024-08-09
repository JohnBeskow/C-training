#ifndef BSTREE_H
#define BSTREE_H

struct treeNode
{
	int nodeValue;
	struct treeNode* left;
	struct treeNode* right;
};

typedef struct treeNode* BSTree;

BSTree emptyTree(void);

int isEmpty(const BSTree tree);

int insertSorted(BSTree* tree, const int data);

void printPreorder(const BSTree tree, FILE* stream);
void printInorder(const BSTree tree, FILE* stream);
void printPostorder(const BSTree tree, FILE* stream);

void printLevelorder(const BSTree tree, FILE* stream);

int find(const BSTree tree, const int data);

void removeElement(BSTree* tree, const int data);

int numberOfNodes(const BSTree tree);

int depth(const BSTree tree);

int minDepth(const BSTree tree);

int* treeToArray(const BSTree tree, int* size);

BSTree* arrayToTree(const int arr[], const int size);

void balanceTree(BSTree* tree);

void mapTree(BSTree* tree, int (*f)(int));

void freeTree(BSTree* tree);

#endif
