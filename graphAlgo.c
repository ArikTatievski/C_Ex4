#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Graph.h"
#include "PriorityQueue.h"

void deleteGraph_cmd(pNode head){
    pNode p = head->next;
    while(p){
        removeNodeFromList(head,p->id);
    }
}

char build_graph_cmd(pNode head){
    deleteGraph_cmd(head);
    char numOfNodes;
    char currNode;
    scanf(" %c",&numOfNodes);
    for(int i=0;i<(int)numOfNodes-48;i++){
        nodeAddToList(head,i);
    }
    char tar1;
    char tar2;
    while (scanf(" %c",&tar1) != EOF){
        if(tar1 == 'A'||tar1 == 'B'||tar1 == 'D'||tar1 == 'S'||tar1 == 'T'){
            return tar1;
        }
        if(tar1 == 'n'){
            scanf(" %c",&currNode);
        }
        else{
            scanf(" %c",&tar2);
            edgeAddToList(getNode(head,(int)currNode - 48),(int)tar2-48,(int)tar1-48);
        }
    }
    return tar1;
}

char insert_node_cmd(pNode head){
    char currNode;
    scanf(" %c",&currNode);
    if (getNode(head,(int)currNode-48) != NULL) {
        removeNodeFromList(head, (int)currNode-48);
    }
    nodeAddToList(head,(int)currNode-48);
    char tar1;
    char tar2;
    while (scanf(" %c",&tar1) != EOF){
        if(tar1 == 'A'||tar1 == 'B'||tar1 == 'D'||tar1 == 'S'||tar1 == 'T'){
            return tar1;
        }
        else{
            scanf(" %c",&tar2);
            edgeAddToList(getNode(head,currNode),(int)tar2-48,(int)tar1-48);
        }
    }
    return tar1;
}
void delete_node_cmd(pNode head){
    int id = 0;
    scanf(" %d",&id);
    removeNodeFromList(head,id);
    return;
}

void relax(pNode head,pEdge e, int src){
    pNode vs= getNode(head,src);
    pNode vd= getNode(head,e->dest);
    int weight_src= vs->wSoFar;
    weight_src=weight_src+e->weight;
    weight_src= abs(weight_src);
    int weight_dest= vd->wSoFar;
    if (weight_src<0){
        return;
    }else{
        if(abs(weight_dest)>abs(weight_src)){
            vd->wSoFar=weight_src;
            vd->father=vs;
        }
    }
}

void dijsktra (pNode head,int key){
    if (head->next==NULL){ // there are no nodes in graph
        return;
    }
    pQueue queue=createPriortyQueue(); // create a priority queue
    pNode temp = head->next;
    while (temp!=NULL){
        if (temp->id==key){
            temp->father=NULL;
            temp->wSoFar=0;
            insert_by_priority(queue,temp);//put in to queue
            temp=temp->next;
            continue;
        }
        temp->father=NULL;
        temp->wSoFar=INFINITY;
        insert_by_priority(queue,temp);//put in to queue
        temp=temp->next;
    }
    while(!(isEmpty(queue))){
        pEdge e;
        pNode curr = deleteByPriority(queue);
        if (curr->firstEdge!=NULL){
            e= curr->firstEdge;
        }
        while (e!=NULL){
            if ((curr->wSoFar+e->weight)>0){ // Infinity+weight(positive) will be -infinity
                relax(head,e,curr->id);
            }
            e=e->next;
        }
    }
    free(queue);
    return;
}

void shortsPath_cmd(pNode head) {
    int src = 0;
    int dest = 0;
    scanf(" %d",&src);
    scanf(" %d",&dest);
    int counter = 0;
    int weight = 0;
    if (src == dest) {
        printf("-1\n");
        return;
    }
    pNode checker = getNode(head, src);
    if (checker->firstEdge == NULL) {
        printf("-1");
        return;
    }
    dijsktra(head, src);
    pNode temp = getNode(head, dest);
    while ((temp->father) != NULL) {
        counter++;
        temp = temp->father;
    }
    temp = getNode(head, dest);
    int arr[counter];
    for (int i = counter - 1; i >= 0; i--) {
        arr[i] = temp->father->id;
        temp = temp->father;
    }
    if (counter == 0) {
        printf("-1\n");
        return;
    }
    temp = getNode(head, dest);
    weight = temp->wSoFar;
    printf("Dijsktra shortest path: %d\n", weight);
    return;

}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int permute(int cities[], int l, int r, int len, int currWeight, pNode head, int ans[]){
    if (l == r) {
        int newWeight = 0;
        dijsktra(head,cities[0]);
        for(int j=1;j<len;j++){
            newWeight = newWeight + (getNode(head,cities[j])->wSoFar);
        }
        if(newWeight<currWeight){
            for(int j=0;j<len;j++){
                ans[j] = cities[j];
            }
            return newWeight;
        }
        else{
            return currWeight;
        }
    }
    else{
        for (int i = l; i <= r; i++){
            swap(&(cities[l]), &(cities[i]));
            currWeight = permute(cities, l+1, r,len,currWeight,head,ans);
            swap(&(cities[l]), &(cities[i])); //backtrack
        }
    }
    return currWeight;
}

void TSP_cmd(pNode head){
    char numOfCities = 0;
    scanf(" %c",&numOfCities);
    int cities[(int)numOfCities-48];
    for(int i=0;i<(int)numOfCities-48;i++){
        char k;
        scanf(" %c",&k);
        cities[i] = (int)k-48;
    }
    int ans[(int)numOfCities-48];
    int totalWeight = permute(cities,0,(int)numOfCities-48-1,(int)numOfCities-48,1000000,head,ans);
    printf("TSP shortest path: %d\n",totalWeight);
}

