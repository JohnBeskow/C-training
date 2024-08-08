
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


//unders�ker om grafen �r tom
int isGraphEmpty(Graph g)
{
    if(g.size == 0)
        return 1;
    return 0;
}

//l�gg till en nod till grafen med v�rdet value
//noden ska f� ett ID automatiskt
//IDt returneras
int addVertex(Graph* g, int value){
    g->arrayOfNodes = (Vertex*)realloc(g->arrayOfNodes, (g->size + 1) * sizeof(Vertex));
    g->arrayOfNodes[g->size].edges = createEmptyList();
    g->arrayOfNodes[g->size].value = value;
    g->arrayOfNodes[g->size].visited = 0;
    g->size++;
    return g->size-1; // om vi l�ger in en nod, d� dem kommer vara 1, men om jag g�r -1 s� idt kommer bli 0
}

//tips: g�r med hj�lp av addDirectedEdge()
void addEdge(Graph g, int vertexID1, int vertexID2, int edgeWeight){
    addDirectedEdge(g, vertexID1, vertexID2, edgeWeight); // g�r s� dirrected edge �r riktad f�r b�da h�llen
    addDirectedEdge(g, vertexID2, vertexID1, edgeWeight);
}

//l�gger till en riktad b�ge i grafen
void addDirectedEdge(Graph g, int startVertexID, int endVertexID, int edgeWeight){
    Data temp;
    temp.id = endVertexID;
    temp.weight = edgeWeight;
    addFirst(&g.arrayOfNodes[startVertexID].edges, temp);
}

//skriver ut alla noder i ID-ordning, och deras v�rden
//skriver ocks� ut alla utg�ende b�gar
void printGraphByID(Graph g){
    printf("ORIGINAL GRAF BY ID!!!!!!\n\n");
    for(int i= 0; i<g.size; i++){
        printf("(ID: %d | Value: %d) ",i, g.arrayOfNodes[i].value);
        printList(g.arrayOfNodes[i].edges, stdout);
    }
}

static void DFS_sub(Graph g, Stack* s){
    if(!isStackEmpty(*s)){
        //h�mta index l�ngst fram i stacken
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
                restList = restList->rest; //jag har getRemainingList, men det h�r �r kortare
            }
        }
        DFS_sub(g, s);
    }
}

//skriv ut alla noder+b�gar i DFS-ordning, startar i en specifik nod
//tar nodens ID
void printGraphDFS(Graph g, int startVertexID){
    printf("GRAF PRINTED AS DFS!!!!!!\n\n");
    Stack s = createStack();
    Data temp;
    temp.id = startVertexID;
    push(&s, temp);
    DFS_sub(g, &s);
    //iterera genom alla flagor och s�tta dem till noll
    for(int i =0 ; i<g.size; i++){
        g.arrayOfNodes[i].visited = 0;

    }
}


static void BFS_sub(Graph g, Queue* q){
    if(!isQueueEmpty(*q)){
        //h�mta index l�ngst fram i k�n
        Data currentVertexID = dequeue(q);
        //if node inte flaggad
        if(!g.arrayOfNodes[currentVertexID.id].visited){
            //print ID, value och weight
            printf("(ID: %d | Value: %d) ",currentVertexID.id, g.arrayOfNodes[currentVertexID.id].value);
            printList(g.arrayOfNodes[currentVertexID.id].edges, stdout);

        //flagga the current node
            g.arrayOfNodes[currentVertexID.id].visited = 1;

        //add rest av list i k�n
            List restList = g.arrayOfNodes[currentVertexID.id].edges;
            while(!isEmpty(restList)){
                enqueue(q, getFirstElement(restList));
                restList = restList->rest; //jag har getRemainingList, men det h�r �r kortare
            }
        }
        BFS_sub(g, q);
    }
}

//skriv ut alla noder+b�gar i BFS-ordning, startar i en specifik nod
//tar nodens ID
void printGraphBFS(Graph g, int startVertexID){
    printf("GRAF PRINTED AS BFS!!!!!!\n\n");
    Queue q = createQueue();
    Data temp;
    temp.id = startVertexID;
    enqueue(&q, temp);
    BFS_sub(g, &q);
    //iterera genom alla flagor och s�tta dem till noll
    for(int i =0 ; i<g.size; i++){
        g.arrayOfNodes[i].visited = 0;

    }
}


//t�mmer/frig�r alla delar av grafen
void clearGraph(Graph* g){
    for(int i=0;i<g->size; i++)
        clearList(&g->arrayOfNodes[i].edges);
     g->size=0;
     //free(g->arrayOfNodes); //det blev fel n�r jag anv�nde den, men det funkade bra utan den, har ingen anning om jag beh�ver den bara f�r jag har redan realloc <3
     printf("Graph is now size %d \n\n", g->size);
}
