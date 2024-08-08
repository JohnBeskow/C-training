
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graf.h"

//skapar en tom graf
Graph createEmptyGraph()
{
    Graph g;
    g.size = 0;
    g.arrayOfNodes = NULL;

    return g;
}


//undersöker om grafen är tom
int isGraphEmpty(Graph g)
{
    if(g.size == 0)
        return 1;
    return 0;
}

//lägg till en nod till grafen med värdet value
//noden ska få ett ID automatiskt
//IDt returneras
int addVertex(Graph* g, int value){
    g->arrayOfNodes = (Vertex*)realloc(g->arrayOfNodes, (g->size + 1) * sizeof(Vertex));
    g->arrayOfNodes[g->size].edges = createEmptyList();
    g->arrayOfNodes[g->size].value = value;
    g->arrayOfNodes[g->size].visited = 0;
    g->size++;
    return g->size-1; // om vi läger in en nod, då dem kommer vara 1, men om jag gör -1 så idt kommer bli 0
}

//tips: gör med hjälp av addDirectedEdge()
void addEdge(Graph g, int vertexID1, int vertexID2, int edgeWeight){
    addDirectedEdge(g, vertexID1, vertexID2, edgeWeight); // gör så dirrected edge är riktad för båda hållen
    addDirectedEdge(g, vertexID2, vertexID1, edgeWeight);
}

//lägger till en riktad båge i grafen
void addDirectedEdge(Graph g, int startVertexID, int endVertexID, int edgeWeight){
    Data temp;
    temp.id = endVertexID;
    temp.weight = edgeWeight;
    addFirst(&g.arrayOfNodes[startVertexID].edges, temp);
}

//skriver ut alla noder i ID-ordning, och deras värden
//skriver också ut alla utgående bågar
void printGraphByID(Graph g){
    printf("ORIGINAL GRAF BY ID!!!!!!\n\n");
    for(int i= 0; i<g.size; i++){
        printf("(ID: %d | Value: %d) ",i, g.arrayOfNodes[i].value);
        printList(g.arrayOfNodes[i].edges, stdout);
    }
}

static void DFS_sub(Graph g, Stack* s){
    if(!isStackEmpty(*s)){
        //hämta index längst fram i stacken
        Data currentVertexID = pop(s);
        //if node inte flaggad
        if(!g.arrayOfNodes[currentVertexID.id].visited){
            //print ID, value och weight
            printf("(ID: %d | Value: %d) ",currentVertexID.id, g.arrayOfNodes[currentVertexID.id].value);
            printList(g.arrayOfNodes[currentVertexID.id].edges, stdout);

        //flagga the current node
            g.arrayOfNodes[currentVertexID.id].visited = 1;

        //add rest av list i Stack
            List restList = g.arrayOfNodes[currentVertexID.id].edges;
            while(!isEmpty(restList)){
                push(s, getFirstElement(restList));
                restList = restList->rest; //jag har getRemainingList, men det här är kortare
            }
        }
        DFS_sub(g, s);
    }
}

//skriv ut alla noder+bågar i DFS-ordning, startar i en specifik nod
//tar nodens ID
void printGraphDFS(Graph g, int startVertexID){
    printf("GRAF PRINTED AS DFS!!!!!!\n\n");
    Stack s = createStack();
    Data temp;
    temp.id = startVertexID;
    push(&s, temp);
    DFS_sub(g, &s);
    //iterera genom alla flagor och sätta dem till noll
    for(int i =0 ; i<g.size; i++){
        g.arrayOfNodes[i].visited = 0;

    }
}


static void BFS_sub(Graph g, Queue* q){
    if(!isQueueEmpty(*q)){
        //hämta index längst fram i kön
        Data currentVertexID = dequeue(q);
        //if node inte flaggad
        if(!g.arrayOfNodes[currentVertexID.id].visited){
            //print ID, value och weight
            printf("(ID: %d | Value: %d) ",currentVertexID.id, g.arrayOfNodes[currentVertexID.id].value);
            printList(g.arrayOfNodes[currentVertexID.id].edges, stdout);

        //flagga the current node
            g.arrayOfNodes[currentVertexID.id].visited = 1;

        //add rest av list i kön
            List restList = g.arrayOfNodes[currentVertexID.id].edges;
            while(!isEmpty(restList)){
                enqueue(q, getFirstElement(restList));
                restList = restList->rest; //jag har getRemainingList, men det här är kortare
            }
        }
        BFS_sub(g, q);
    }
}

//skriv ut alla noder+bågar i BFS-ordning, startar i en specifik nod
//tar nodens ID
void printGraphBFS(Graph g, int startVertexID){
    printf("GRAF PRINTED AS BFS!!!!!!\n\n");
    Queue q = createQueue();
    Data temp;
    temp.id = startVertexID;
    enqueue(&q, temp);
    BFS_sub(g, &q);
    //iterera genom alla flagor och sätta dem till noll
    for(int i =0 ; i<g.size; i++){
        g.arrayOfNodes[i].visited = 0;

    }
}


//tömmer/frigör alla delar av grafen
void clearGraph(Graph* g){
    for(int i=0;i<g->size; i++)
        clearList(&g->arrayOfNodes[i].edges);
     g->size=0;
     //free(g->arrayOfNodes); //det blev fel när jag använde den, men det funkade bra utan den, har ingen anning om jag behöver den bara för jag har redan realloc <3
     printf("Graph is now size %d \n\n", g->size);
}
