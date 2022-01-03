#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Graph.h"
#include "graphAlgo.h"

int main() {
    pNode graph = newNode(-1,NULL);
    char ch;
    nodeAddToList(graph,0);
    nodeAddToList(graph,1);
    edgeAddToList(getNode(graph,0),5,1);

    while(scanf("%c",&ch) != EOF){
//        pNode p = graph->next;
//        while (p){
//            printf("Node %d:\n",p->id);
//            pEdge e = p->firstEdge;
//            while (e){
//                printf("%d->%d ,weight %d",p->id,e->dest,e->weight);
//                e=e->next;
//            }
//            p=p->next;
//        }
        switch (ch) {
            case 'A':
                ch = build_graph_cmd(graph);

            case 'B':
                ch = insert_node_cmd(graph);

            case 'D':
                delete_node_cmd(graph);
                break;

            case 'S':
                shortsPath_cmd(graph);
                break;

            case 'T':
                TSP_cmd(graph);
                break;
        }
    }
    return 0;
}
