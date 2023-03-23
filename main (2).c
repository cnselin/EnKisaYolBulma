//Zeynep Irem Akyalçın 210501008
//Selime Selin Can 210501005

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Graftaki dugum sayisi
#define V 7

// Minimum uzaklik degerini bulan fonksiyon
int minDistance(int dist[], bool sptSet[])
{
    // Minimum deger initialize edilir
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Mesafeyi yazdiran fonksiyon
void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Dijkastra algoritmasini uygulayan fonksiyon
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 

    bool sptSet[V]; 

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;


    dist[src] = 0;


    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet);


        sptSet[u] = true;


        for (int v = 0; v < V; v++)


            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }


    printSolution(dist);
}


int main()
{

    int graph[V][V] = { { 0, 6, 8, 0, 3, 0, 6 },
                        { 6, 0, 12, 7, 8, 0, 0 },
                        { 8, 12, 0, 0, 0, 0, 0 },
                        { 0, 7, 0, 0, 4, 2, 0 },
                        { 3, 8, 0, 4, 0, 3, 4 },
                        { 0, 0, 0, 2, 3, 0, 3 },
                        { 6, 0, 0, 0, 4, 3, 0 } };



    dijkstra(graph, 0);

    return 0;
}