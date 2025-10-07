#include <stdio.h>
#define INF 99999  // Representing infinity

// Number of vertices in the graph
#define V 4

// Function to print the solution matrix
void printSolution(int dist[V][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Function that implements Floyd-Warshall Algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];  // Output matrix (shortest distances)

    // Step 1: Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Step 2: Update dist[][] for each possible intermediate vertex k
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, update dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Step 3: Print the shortest distance matrix
    printSolution(dist);
}

// Driver code
int main() {
    int graph[V][V] = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    floydWarshall(graph);
    return 0;
}
