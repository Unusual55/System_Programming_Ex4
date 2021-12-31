#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"algo.h"

typedef struct GRAPH_NODE_ *pnode;
;

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

int main();
int graphexist = 0;

int main()
{
    struct GRAPH_NODE_ *graph;
    graph = (struct GRAPH_NODE_ *)malloc(1 * sizeof(struct GRAPH_NODE_));
    int size = 1;
    if (!graph)
    {
        exit(1);
    }
    char c;
    int input = 0;
    while (1)
    {
        if (input == 0)
        {
            scanf(" %c", &c);
        }
        if (c == 'A')
        {
            free(graph->edges);
            free(graph);
            graphexist = 1;
            int size;
            scanf(" %d", &size);
            graph = (struct GRAPH_NODE_ *)malloc(size * sizeof(struct GRAPH_NODE_));
            if (graph == NULL)
            {
                exit(1);
            }
            for (int i = 0; i < size; i++)
            {
                graph[i].node_num = i;
                graph[i].edges = NULL;
                graph[i].edges = (pedge)malloc(sizeof(edge));
                graph[i].edges->endpoint = &graph[i];
                graph[i].edges->weight = -1;
                graph[i].edges->next = NULL;
            }
            int curr = -1;
            scanf(" %c", &c);
            while (1)
            {
                if (c == 'n')
                {
                    scanf("%d", &curr);
                    char ch;
                    while (1)
                    {
                        scanf(" %c", &ch);
                        if (ch == 'n')
                        {
                            c = 'n';
                            break;
                        }
                        if (ch < '0' || ch > '9')
                        {
                            input = 1;
                            c = ch;
                            break;
                        }
                        else
                        {
                            int dest = ch - 48;
                            int weight;
                            scanf("%d", &weight);
                            pedge edge = graph[curr].edges;
                            while (edge->next != NULL)
                            {
                                edge = edge->next;
                            }
                            edge->next = (pedge)malloc(sizeof(edge));
                            edge->next->weight = weight;
                            edge->next->endpoint = &(graph[dest]);
                        }
                    }
                }
            }
        }

        // end of A

        if (c == 'B')
        {
            int vernum = -1;
            int flag = 0;
            scanf(" %d", &vernum);
            for (int i = 0; i < size; i++)
            {
                if (vernum == graph[i].node_num)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                size += 1;
                graph = (pnode)realloc(graph, size * sizeof(struct GRAPH_NODE_));
                if (graph != NULL)
                {
                    exit(1);
                }
                graph[size - 1].node_num = vernum;
                graph[size - 1].edges = NULL;
                graph[size - 1].edges = (pedge)malloc(sizeof(edge));
                graph[size - 1].edges->weight = -1;
                graph[size - 1].edges->endpoint = &graph[size];
                graph[size - 1].edges->next = NULL;
                char dest;
                int weight;
                while (1)
                {
                    scanf(" %c", &dest);
                    if (dest < '0' || dest > '9')
                    {
                        c = dest;
                        break;
                    }
                    scanf(" %d", &weight);
                    pedge run = graph[size].edges->next;
                    while (run->next != NULL)
                    {
                        run = run->next;
                    }
                    int i = -1;
                    for (int i = 0; i < size + 1; i++)
                    {
                        if (graph[i].node_num == dest - 48)
                        {
                            break;
                        }
                    }
                    if (i == -1)
                    {
                        continue;
                    }
                    run->next = (pedge)malloc(sizeof(edge));
                    run->next->weight = weight;
                    run->next->endpoint = &graph[i];
                }
            }
            else
            {
                int i = 0;
                for (int i = 0; i < size - 1; i++)
                {
                    if (graph[i].next != NULL && graph[i].next->node_num == vernum)
                    {
                        break;
                    }
                }
                pnode up = graph[i].next;
                free(up->edges);
                char dest;
                int weight;
                while (1)
                {
                    scanf(" %c", &dest);
                    if (dest < '0' || dest > '9')
                    {
                        return dest;
                    }
                    scanf("%d", &weight);
                    pedge run = graph[size].edges->next;
                    while (run->next != NULL)
                    {
                        run = run->next;
                    }
                    int j = -1;
                    for (int j = 0; j < size + 1; j++)
                    {
                        if (graph[j].node_num == dest - 48)
                        {
                            break;
                        }
                    }
                    if (j == -1)
                    {
                        continue;
                    }
                    run->next = (pedge)malloc(sizeof(edge));
                    run->next->weight = weight;
                    run->next->endpoint = &graph[j + 1];
                }
            }
        }

        // end of B

        if (c == 'D')
        {
            int removed=-1;
            removed = scanf(" %d", &removed);
            int j;
            for (int i = -1; i < size - 1; i++)
            {
                if (&graph[i + 1] != NULL && graph[i + 1].node_num != removed)
                {
                    remove_edges(&graph[i+1]);
                }
                else
                {
                    j = i;
                }
            }
            free(graph[j + 1].edges);
            pnode todel = graph[j + 1].next;
            graph[j].next = todel->next;
            free(todel);
            graph = (pnode)realloc(graph, (size-1) * sizeof(struct GRAPH_NODE_));
            size -= 1;
        }

        //end of 'D'

        if(c=='T'){
            int arr[6];
            int counter=0;
            char key=-1;
            while(counter<6){
                scanf(" %c", &key);
                if(key<'0' || key>'9'){
                    break;
                }
                arr[0+counter]=key-48;
            }
            if(sizeof(arr)/sizeof(int)<6){
                int len=sizeof(arr)/sizeof(int);
                int newarr[len];
                for(int p=0; p<len;p++){
                    newarr[p]=arr[p];
                }
                int arr[4]=newarr;
            }
            if(sizeof(arr)/sizeof(int)>1){
                TSP(graph, arr);
            }
            else{
                printf("-1");
            }
        }
    
        //end of 'T'
    }
}