#include <limits.h>

#include "algo.h"
#include "edges.h"
#include "graph.h"
#include "nodes.h"
#include "queue.h"

void dijkstra(int *arr, pnode source) {
    qnode *source_queue = new_queue_node(source, 0);
    while (!is_empty(&source_queue)) {
        source = pop(&source_queue);
        pedge curr_edge = source->edges;
        while (curr_edge) {
            if (arr[source->index] + curr_edge->weight < arr[curr_edge->endpoint->index]) {
                arr[curr_edge->endpoint->index] = arr[source->index] + curr_edge->weight;
                push(&source_queue, curr_edge->endpoint, arr[curr_edge->endpoint->index]);
            }
            curr_edge = curr_edge->next;
        }
    }
}

void permutation(int *cities, int start, int end, int number_of_nodes, int *ans, pnode head) {
    if (start == end) {
        int route_len = 0;
        int *dij = (int *)malloc(sizeof(int) * number_of_nodes);
        for (int i = 0; i < number_of_nodes; i++) {
            dij[i] = INT_MAX;
        }
        pnode source = find_node(cities[0], head);
        dij[source->index] = 0;
        for (int i = 1; i <= end; i++) {
            dijkstra(dij, source);
            if (dij[find_node(cities[i], head)->index] == INT_MAX) {
                free(dij);
                return;
            }
            source = find_node(cities[i], head);
            route_len = route_len + dij[source->index];
            for (int j = 0; j < number_of_nodes; j++) {
                dij[j] = INT_MAX;
            }
            dij[source->index] = 0;
        }
        free(dij);
        if (route_len < *ans && route_len != 0) {
            *ans = route_len;
        }
        return;
    }
    for (int k = start; k <= end; k++) {
        swap(cities + k, cities + start);
        permutation(cities, start + 1, end, number_of_nodes, ans, head);
        swap(cities + k, cities + start);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}