#include "list.h"
#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "graf.h"



int main()
{

    Graph g = createEmptyGraph();

    addVertex(&g, 0); //skapade node 0 men hoppade över den för att den skulle se precis ut som exempelt i dfs för att se att den fungerade som den skulle
    addVertex(&g, 1);
    addVertex(&g, 2); // mata in dem i index ordning, so numret som är brevid &g, är value av noden
    addVertex(&g, 3);
    addVertex(&g, 4);
    addVertex(&g, 5);
    addVertex(&g, 6);
    addVertex(&g, 7);
    addVertex(&g, 8);
    addVertex(&g, 9);
    addVertex(&g, 10);
    addVertex(&g, 11);
    addVertex(&g, 12);

    addEdge(g,1,2,99); // matar in varje båge av varje nod som den är kopplad till
    addEdge(g,1,7,99);
    addEdge(g,1,8,99);

    addEdge(g,2,3,99);
    addEdge(g,2,6,99);

    addEdge(g,3,4,99);
    addEdge(g,3,5,99);

    addEdge(g,8,9,99);
    addEdge(g,8,12,99);

    addEdge(g,9,10,99);
    addEdge(g,9,11,99);



    printGraphByID(g);


    printGraphBFS(g, 1);


    printGraphDFS(g,1);

    clearGraph(&g);

    addVertex(&g, 6);

    printGraphByID(g);


    return 0;
}
