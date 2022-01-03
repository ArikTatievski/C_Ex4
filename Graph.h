#ifndef EX4_EDGE_H
#define EX4_EDGE_H


typedef struct Edge {
    int weight;
    int dest;
    struct Edge *next;
} edge, *pEdge;

typedef struct Node{
    int id;
    struct Node* next;
    struct Edge* firstEdge;
    int wSoFar;
    struct Node* father;
}node,*pNode;

pNode newNode(int id, pNode next);
pNode getNode(pNode head,int id);
void nodeAddToList(pNode head, int id);
void removeNodeFromList(pNode head, int key);
void removeOutEdges(pNode head,int key);

pEdge newEdge(int weight, int dest);
pEdge getEdge(pNode src, int dest);
void edgeAddToList(pNode src, int weight, int dest);
void removeEdgeFromList(pNode src,int dest);


#endif //EX4_EDGE_H
