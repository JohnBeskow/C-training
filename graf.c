
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graf.h"

Graph createEmptyGraph()
{
    Graph g;
    g.size = 0;
    g.arrayOfNodes = NULL;

    return g;
}


int isGraphEmpty(Graph g)
{
    if(g.size == 0)
        return 1;
    return 0;
}

int addVertex(Graph* g, int value){
    g->arrayOfNodes = (Vertex*)realloc(g->arrayOfNodes, (g->size + 1) * sizeof(Vertex));
    g->arrayOfNodes[g->size].edges = createEmptyList();
    g->arrayOfNodes[g->size].value = value;
    g->arrayOfNodes[g->size].visited = 0;
    g->size++;
    return g->size-1; 
}

void addEdge(Graph g, int vertexID1, int vertexID2, int edgeWeight){
    addDirectedEdge(g, vertexID1, vertexID2, edgeWeight); 
    addDirectedEdge(g, vertexID2, vertexID1, edgeWeight);
}

void addDirectedEdge(Graph g, int startVertexID, int endVertexID, int edgeWeight){
    Data temp;
    temp.id = endVertexID;
    temp.weight = edgeWeight;
    addFirst(&g.arrayOfNodes[startVertexID].edges, temp);
}

void printGraphByID(Graph g){
    printf("ORIGINAL GRAF BY ID!!!!!!\n\n");
    for(int i= 0; i<g.size; i++){
        printf("(ID: %d | Value: %d) ",i, g.arrayOfNodes[i].value);
        printList(g.arrayOfNodes[i].edges, stdout);
    }
}

static void DFS_sub(Graph g, Stack* s){
    if(!isStackEmpty(*s)){
        Data currentVertexID = pop(s);
        if(!g.arrayOfNodes[currentVertexID.id].visited){
            printf("(ID: %d | Value: %d) ",currentVertexID.id, g.arrayOfNodes[currentVertexID.id].value);
            printList(g.arrayOfNodes[currentVertexID.id].edges, stdout);

            g.arrayOfNodes[currentVertexID.id].visited = 1;

            List restList = g.arrayOfNodes[currentVertexID.id].edges;
            while(!isEmpty(restList)){
                push(s, getFirstElement(restList));
                restList = restList->rest; 
            }
        }
        DFS_sub(g, s);
    }
}

void printGraphDFS(Graph g, int startVertexID){
    printf("GRAF PRINTED AS DFS!!!!!!\n\n");
    Stack s = createStack();
    Data temp;
    temp.id = startVertexID;
    push(&s, temp);
    DFS_sub(g, &s);
    for(int i =0 ; i<g.size; i++){
        g.arrayOfNodes[i].visited = 0;

    }
}


static void BFS_sub(Graph g, Queue* q){
    if(!isQueueEmpty(*q)){
        Data currentVertexID = dequeue(q);
        if(!g.arrayOfNodes[currentVertexID.id].visited){
            printf("(ID: %d | Value: %d) ",currentVertexID.id, g.arrayOfNodes[currentVertexID.id].value);
            printList(g.arrayOfNodes[currentVertexID.id].edges, stdout);

            g.arrayOfNodes[currentVertexID.id].visited = 1;

            List restList = g.arrayOfNodes[currentVertexID.id].edges;
            while(!isEmpty(restList)){
                enqueue(q, getFirstElement(restList));
                restList = restList->rest; 
            }
        }
        BFS_sub(g, q);
    }
}

void printGraphBFS(Graph g, int startVertexID){
    printf("GRAF PRINTED AS BFS!!!!!!\n\n");
    Queue q = createQueue();
    Data temp;
    temp.id = startVertexID;
    enqueue(&q, temp);
    BFS_sub(g, &q);
    for(int i =0 ; i<g.size; i++){
        g.arrayOfNodes[i].visited = 0;

    }
}


void clearGraph(Graph* g){
    for(int i=0;i<g->size; i++)
        clearList(&g->arrayOfNodes[i].edges);
     g->size=0;
     printf("Graph is now size %d \n\n", g->size);
}
