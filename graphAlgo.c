#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Graph.h"

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
        printf("node %d created\n",i);
    }
    char tar1;
    char tar2;
    while (scanf(" %c",&tar1) != EOF){
        printf("Scanned %c\n",tar1);
        if(tar1 == 'A'||tar1 == 'B'||tar1 == 'D'||tar1 == 'S'||tar1 == 'T'){
            printf("Detected a new function: %c",tar1);
            return tar1;
        }
        if(tar1 == 'n'){
            scanf(" %c",&currNode);
            printf("Current node is %d\n",(int)currNode-48);
        }
        else{
            scanf(" %c",&tar2);
            edgeAddToList(getNode(head,(int)currNode - 48),(int)tar2-48,(int)tar1-48);
            printf("Edge created %d->%d(%d)\n",(int)currNode - 48,(int)tar1-48,(int)tar2-48);
        }
    }
    return tar1;
}

char insert_node_cmd(pNode head){
    char currNode;
    scanf(" %c",&currNode);
    if (getNode(head,(int)currNode-48) != NULL) {
        removeNodeFromList(head, (int)currNode-48);
        printf("This node exists - removing it");
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
            printf("Edge created %d->%d(%d)\n",(int)currNode - 48,(int)tar1-48,(int)tar2-48);
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

void dijkstra(pNode head, int id){

}

void shortsPath_cmd(pNode head){

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
        dijkstra(head,cities[0]);
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
    printf("TSP shortest path: %d",totalWeight);
}

