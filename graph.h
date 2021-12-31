#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

void remove_edges(pnode vertex);
//char insert_node_cmd(pnode* head, int id, int size);
//char update_node_cmd(pnode* head, int id, int size);
//void delete_node_cmd(pnode* head, int id, int size);
void printGraph_cmd(pnode head); // for self debug
void deleteGraph_cmd(pnode *head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);


#endif
