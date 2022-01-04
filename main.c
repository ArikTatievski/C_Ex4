#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Graph.h"
#include "graphAlgo.h"

int main() {
    pNode graph = newNode(-1,NULL);
    char ch;
    while (scanf(" %c",&ch) != EOF){
        while (1){
            if(ch=='A'){
                ch = build_graph_cmd(graph);
                continue;
            }
            if(ch == 'B'){
                ch = insert_node_cmd(graph);
                continue;
            }
            if(ch == 'D'){
                delete_node_cmd(graph);
                break;
            }
            if(ch == 'S'){
                shortsPath_cmd(graph);
                break;
            }
            if(ch == 'T') {
                TSP_cmd(graph);
                break;
            } else{
                break;
            }
        }

    }
    deleteGraph_cmd(graph);
    free(graph);
    return 0;
}
