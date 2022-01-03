#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Graph.h"

pNode newNode(int id, pNode next){
    node *p = (node*) malloc (sizeof(node));
    p->id = id;
    p->next = next;
    p->firstEdge = NULL;
    p->wSoFar = 0;
    p->father = NULL;
    return p;
}

pNode getNode(pNode head,int id){
    pNode p = head->next;
    while (p){
        if (p->id == id){
            return p;
        }
        p=p->next;
    }
    return p;
}

void nodeAddToList(pNode head, int id){
    pNode n = head->next;
    if (n == NULL){
        pNode curr = newNode(id,NULL);
        head->next = curr;
        return;
    }

    while (n->next){
        n=n->next;
    }
    pNode curr = newNode(id,NULL);
    n->next = curr;
}
void removeNodeFromList(pNode head,int key){
    pNode temp = head->next;
    if (temp==NULL){
        return;
    }
    if(temp->id==key){
        if (temp->next == NULL){
            head->next=NULL;
            removeOutEdges(head,key);
            return;
        }
        else{
            while (temp->firstEdge){
                pEdge e= temp->firstEdge;
                removeEdgeFromList(temp,e->dest);
            }
            head->next=temp->next;
            free(temp);
            removeOutEdges(head,key);
            return;
        }
    } else{
        while (temp->next!=NULL){
            pNode checker= temp->next;
            if (checker->id==key){
                while (checker->firstEdge!=NULL){
                    pEdge e= checker->firstEdge;
                    removeEdgeFromList(checker,e->dest);
                }
                temp->next=checker->next;
                free(checker);
                removeOutEdges(head,key);
                return;
            }
            temp=temp->next;
        }
    }
    return;
}
void removeOutEdges(pNode head,int key){
    pNode p = head->next;
    while(p){
        pEdge e = p->firstEdge;
        while(e){
            if(e->dest == key){
                removeEdgeFromList(p,key);
            }
            e=e->next;
        }
        p=p->next;
    }
}