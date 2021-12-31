#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_
{
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_
{
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;


void remove_edges(pnode vertex);

void remove_edges(pnode vertex)
{
    int id = vertex->node_num;
    pedge run=vertex->edges->next;
    while (run->next != NULL)
    {
        if (run->next->endpoint->node_num == id)
        {
            pedge nxtedge = run->next;
            run->next=nxtedge->next;
            free(nxtedge);
            break;
        }
    }
}

//char insert_node_cmd(pnode* head, int id, int size){
//     head=(pnode*) realloc(head, (size+1)*sizeof(node));
//     head[size]->node_num=id;
//     head[size]->edges=NULL;
//     head[size]->edges=(pedge) malloc(sizeof(edge));
//     head[size]->edges->weight=-1;
//     head[size]->edges->endpoint=&head[size];
//     head[size]->edges->next=NULL;
//     char dest;
//     int weight;
//     while(1){
//         scanf(" %c", &dest);
//         if(dest<'0' || dest>'9'){
//             return dest;
//         }
//         scanf(" %d", &weight);
//         pedge run=head[size]->edges;
//         while(run->next!=NULL){
//             run=run->next;
//         }
//         int i=-1;
//         for(int i=0; i<size+1; i++){
//             if(head[i]->node_num==dest-48){
//                 break;
//             }
//         }
//         if(i==-1){
//             continue;
//         }
//         run->next=(pedge) malloc(sizeof(edge));
//         run->next->weight=weight;
//         pnode o = head[i];
//         run->next->endpoint=&o;
//     }
// }

// char update_node_cmd(pnode* head, int id, int size){
//     int i=0;
//     for(int i=0;i<size-1;i++){
//         if(head[i]->next!=NULL && head[i]->next->node_num==id){
//             break;
//         }
//     }
//     pnode up=head[i]->next;
//     free(up->edges);
//     char dest;
//     int weight;
//     while(1){
//         scanf(" %c", &dest);
//         if(dest<'0' || dest>'9'){
//             return dest;
//         }
//         scanf("%d", &weight);
//         pedge run=head[size]->edges->next;
//         while(run->next!=NULL){
//             run=run->next;
//         }
//         int j=-1;
//         for(int j=0; j<size+1; j++){
//             if(head[j]->node_num==dest-48){
//                 break;
//             }
//         }
//         if(j==-1){
//             continue;
//         }
//         run->next=(pedge) malloc(sizeof(edge));
//         run->next->weight=weight;
//         run->next->endpoint=&head[j+1];
//     }

// }

//void delete_node_cmd(pnode* head, int id, int size){
//     int j;
//     for(int i=-1; i<size-1; i++){
//         if(head[i+1]!=NULL && head[i+1]->node_num!=id){
//             remove_edges(head[i]);
//         }
//         else{
//             j=i;
//         }
//     }
//     free(head[j+1]->edges);
//     pnode todel = head[j+1]->next;
//     head[j]->next=todel->next;
//     free(todel);
//     head=(pnode*) realloc(head, (size-1)*sizeof(node));
// }