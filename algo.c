#include <stdio.h>
#include <stdlib.h>
#include "algo.h"

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

int find_index(pnode head, int id)
{
    pnode run = head->next;
    int i = 0;
    while (!run)
    {
        if (run->node_num == id)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int get_weight(pnode head, int src, int dest)
{
    int isrc = find_index(head, src);
    int idest = find_index(head, dest);
    if (isrc == -1 || idest == -1)
    {
        return -1;
    }
    pedge ed = &head[isrc].edges->next;
    while (!ed)
    {
        if (ed->endpoint->node_num == dest)
        {
            return ed->weight;
        }
        ed = ed->next;
    }
    return;
}

void TSP(pnode head, int *nodes)
{
    int ispath = -1;
    int mindist = __INT_MAX__;
    int length = (sizeof(nodes)) / (sizeof(int));
    int path[length];

    for (int a = 0; a < length; a++)
    {
        if (length == 1)
        {
            return nodes[a];
        }

        for (int b = 0; b < length && length >= 2; b++)
        {
            if (b == a)
            {
                continue;
            }
            double ab = get_weight(head, nodes[a], nodes[b]);
            if (ab == -1)
            {
                continue;
            }
            if(length==2){
                        if(ab<mindist){
                            mindist=ab;
                            path[0]=nodes[a];
                            path[1]=nodes[b];
                            ispath=1;
                        }
                    }

            for (int c = 0; c < length && length >= 3; c++)
            {
                if (c == a || c == b)
                {
                    continue;
                }
                double bc = get_weight(head, nodes[b], nodes[c]);
                if (bc == -1)
                {
                    continue;
                }
                if(length==3){
                        if(ab+bc<mindist){
                            mindist=ab+bc;
                            path[0]=nodes[a];
                            path[1]=nodes[b];
                            path[2]=nodes[c];
                            ispath=1;
                        }
                    }

                for (int d = 0; d < length && length >= 4; d++)
                {
                    if (d == a || d == b || d == c)
                    {
                        continue;
                    }
                    double cd = get_weight(head, nodes[c], nodes[d]);
                    if (cd == -1)
                    {
                        continue;
                    }
                    if(length==4){
                        if(ab+bc+cd<mindist){
                            mindist=ab+bc+cd;
                            path[0]=nodes[a];
                            path[1]=nodes[b];
                            path[2]=nodes[c];
                            path[3]=nodes[d];
                            ispath=1;
                        }
                    }

                    for (int e = 0; e < length && length >= 5; e++)
                    {
                        if (e == a || e == b || e == c || e == d)
                        {
                            continue;
                        }
                        double de = get_weight(head, nodes[d], nodes[e]);
                        if (de == -1)
                        {
                            continue;
                        }
                        if (length == 5)
                        {
                            if (ab + bc + cd + de < mindist)
                            {
                                mindist = ab + bc + cd + de;
                                path[0] = nodes[a];
                                path[1] = nodes[b];
                                path[2] = nodes[c];
                                path[3] = nodes[d];
                                path[4] = nodes[e];
                                ispath=1;
                            }
                        }

                        for (int f = 0; f < length && length == 6; f++)
                        {
                            if (f == a || f == b || f == c || f == d || f == e)
                            {
                                continue;
                            }
                            double ef = get_weight(head, nodes[e], nodes[f]);
                            if (ef == -1)
                            {
                                continue;
                            }
                            if (ab + bc + cd + de + ef < mindist)
                            {
                                mindist = ab + bc + cd + de + ef;
                                path[0] = nodes[a];
                                path[1] = nodes[b];
                                path[2] = nodes[c];
                                path[3] = nodes[d];
                                path[3] = nodes[e];
                                path[5] = nodes[f];
                                ispath=1;
                            }
                        }
                    }
                }
            }
        }
    }
    if(ispath)
        printf(path);
    else
        printf("-1");
}