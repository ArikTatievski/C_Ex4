#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Graph.h"

pEdge newEdge(int weight, int dest){
    pEdge p = (edge*) malloc (sizeof(edge));
    p->weight = weight;
    p->dest = dest;
    p->next = NULL;
    return p;
}

pEdge getEdge(pNode src, int dest){
    pEdge e = src->firstEdge;
    while (e) {
        if (e->dest == dest){
            return e;
        }
        e=e->next;
    }
    return e;
}

void edgeAddToList(pNode src, int weight, int dest){
    pEdge e = src->firstEdge;
    if (e==NULL){
        pEdge curr = newEdge(weight,dest);
        src->firstEdge = curr;
        printf("Edge %d->%d created\n",src->id,dest);
        return;
    }
    while (e->next){
        e = e->next;
    }
    pEdge curr = newEdge(weight,dest);
    printf("Edge %d->%d created\n",src->id,dest);
    e->next = curr;
}

void removeEdgeFromList(pNode src,int dest){
    pEdge e = src->firstEdge;
    if(e->dest == dest){
        src->firstEdge = e->next;
        free(e);
        e = NULL;
        printf("Edge %d->%d removed\n",src->id,dest);
        return;
    }
    while(e->next){
        if(e->next->dest == dest){
            pEdge temp = e->next;
            e->next = temp->next;
            free(temp);
            printf("Edge %d->%d removed\n",src->id,dest);
            temp = NULL;
            return;
        }
        e=e->next;
    }
}