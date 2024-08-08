#include <stdio.h>
#ifndef GRAF_H
#define GRAF_H
#include "list.h"
#include "queue.h"
#include "stack.h"


typedef struct Vertex
{
    int value;
    List edges;
    int visited;

}Vertex;


typedef struct Graph
{
    int size;
    Vertex* arrayOfNodes;


}Graph;


//skapar en tom graf
Graph createEmptyGraph();


//unders�ker om grafen �r tom
int isGraphEmpty(Graph g);

//l�gg till en nod till grafen med v�rdet value
//noden ska f� ett ID automatiskt
//IDt returneras
int addVertex(Graph* g, int value);

//tips: g�r med hj�lp av addDirectedEdge()
void addEdge(Graph g, int vertexID1,int  vertexID2, int edgeWeight );

//l�gger till en riktad b�ge i grafen
void addDirectedEdge(Graph g,int startVertexID,int endVertexID, int edgeWeight);

//skriver ut alla noder i ID-ordning, och deras v�rden
//skriver ocks� ut alla utg�ende b�gar
void printGraphByID(Graph g);

//skriv ut alla noder+b�gar i DFS-ordning, startar i en specifik nod
//tar nodens ID
void printGraphDFS(Graph g, int startVertexID);

//skriv ut alla noder+b�gar i BFS-ordning, startar i en specifik nod
//tar nodens ID
void printGraphBFS(Graph g, int startVertexID);

//t�mmer/frig�r alla delar av grafen
void clearGraph(Graph* g);

#endif
