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


Graph createEmptyGraph();


int isGraphEmpty(Graph g);

int addVertex(Graph* g, int value);

void addEdge(Graph g, int vertexID1,int  vertexID2, int edgeWeight );

void addDirectedEdge(Graph g,int startVertexID,int endVertexID, int edgeWeight);

void printGraphByID(Graph g);

void printGraphDFS(Graph g, int startVertexID);

void printGraphBFS(Graph g, int startVertexID);

void clearGraph(Graph* g);

#endif
