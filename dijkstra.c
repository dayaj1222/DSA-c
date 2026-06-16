#include <stdio.h>
#define V 6
#define INF 9999
#define NO_PREV -1

// Fills dist[] with shortest distances and prev[] with predecessor nodes.
void dijkstra(int graph[V][V], int dist[V], int prev[V]) {
  int visited[V];
  for (int i = 0; i < V; i++) {
    dist[i] = INF;
    prev[i] = NO_PREV;
    visited[i] = 0;
  }

  int current = 0;
  dist[current] = 0;

  for (int step = 0; step < V; step++) {
    visited[current] = 1;

    // Relax all neighbors of current
    for (int neighbor = 0; neighbor < V; neighbor++) {
      if (graph[current][neighbor] != 0) {
        int new_dist = dist[current] + graph[current][neighbor];
        if (new_dist < dist[neighbor]) {
          dist[neighbor] = new_dist;
          prev[neighbor] = current;
        }
      }
    }

    // Pick the unvisited node with the smallest known distance
    int next = -1;
    int min_dist = INF;
    for (int i = 0; i < V; i++) {
      if (!visited[i] && dist[i] < min_dist) {
        min_dist = dist[i];
        next = i;
      }
    }

    if (next == -1)
      break; // All reachable nodes visited
    current = next;
  }
}

int main() {
  int graph[V][V] = {
      // A  B  C  D  E  F
      {0, 2, 1, 0, 0, 0}, // A
      {0, 0, 0, 4, 1, 0}, // B
      {0, 3, 0, 0, 1, 0}, // C
      {0, 0, 0, 0, 0, 2}, // D
      {0, 0, 0, 2, 0, 3}, // E
      {0, 0, 0, 0, 0, 0}, // F
  };

  int dist[V], prev[V];
  dijkstra(graph, dist, prev);

  printf("Shortest paths from node 0:\n");
  for (int i = 0; i < V; i++) {
    printf("  dist[%d] = %d  |  path: ", i, dist[i]);

    // Reconstruct path by walking prev[] backwards, then reverse-print
    int path[V], path_len = 0;
    for (int v = i; v != NO_PREV; v = prev[v])
      path[path_len++] = v;

    for (int k = path_len - 1; k >= 0; k--) {
      printf("%d", path[k]);
      if (k > 0)
        printf(" -> ");
    }
    printf("\n");
  }
}
