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


//undersöker om grafen är tom
int isGraphEmpty(Graph g);

//lägg till en nod till grafen med värdet value
//noden ska få ett ID automatiskt
//IDt returneras
int addVertex(Graph* g, int value);

//tips: gör med hjälp av addDirectedEdge()
void addEdge(Graph g, int vertexID1,int  vertexID2, int edgeWeight );

//lägger till en riktad båge i grafen
void addDirectedEdge(Graph g,int startVertexID,int endVertexID, int edgeWeight);

//skriver ut alla noder i ID-ordning, och deras värden
//skriver också ut alla utgående bågar
void printGraphByID(Graph g);

//skriv ut alla noder+bågar i DFS-ordning, startar i en specifik nod
//tar nodens ID
void printGraphDFS(Graph g, int startVertexID);

//skriv ut alla noder+bågar i BFS-ordning, startar i en specifik nod
//tar nodens ID
void printGraphBFS(Graph g, int startVertexID);

//tömmer/frigör alla delar av grafen
void clearGraph(Graph* g);

#endif
