#include <stdio.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 5

void printSolution(int path[]);

/* A utility function to check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle constructed so far (stored in 'path[]') */
bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    /* Check if this vertex is an adjacent vertex of the previously added vertex. */
    if (graph[path[pos - 1]][v] == 0)
        return false;

    /* Check if the vertex has already been included. This step can be optimized by creating an array of size V */
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

/* A recursive utility function to solve hamiltonian cycle problem */
bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
    /* base case: If all vertices are included in Hamiltonian Cycle */
    if (pos == V)
    {
        /* And if there is an edge from the last included vertex to the first vertex */
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    /* Try different vertices as a next candidate in Hamiltonian Cycle. We don't try for 0 as we included 0 as starting point in hamCycle() */
    for (int v = 1; v < V; v++)
    {
        /* Check if this vertex can be added to Hamiltonian Cycle */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            /* recur to construct rest of the path */
            if (hamCycleUtil(graph, path, pos + 1) == true)
                return true;

            /* If adding vertex v doesn't lead to a solution, then remove it */
            path[pos] = -1;
        }
    }

    /* If no vertex can be added to Hamiltonian Cycle constructed so far, then return false */
    return false;
}

bool hamCycle(bool graph[V][V])
{
    int *path = new int[V];
    
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamCycleUtil(graph, path, 1) == false)
    {
        printf("\nSolution does not exist");
        return false;
    }

    printSolution(path);
    return true;
}

/* A utility function to print solution */
void printSolution(int path[])
{
    printf("Solution Exists:"
           " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);

    /* Let us print the first vertex again to show the complete cycle */
    printf(" %d ", path[0]);
    printf("\n");
}

int main()
{
    bool graph1[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    // Print the solution
    hamCycle(graph1);
    
    bool graph2[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
    };

    // Print the solution
    hamCycle(graph2);

    return 0;
}