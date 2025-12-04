#include <iostream>
using namespace std;
int main()
{
    int n;
    int cost[20][20];
    int dist[20];
    int visited[20];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter cost adjacency matrix (999 for no edge):\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> cost[i][j];
    int start;
    cout << "Enter start vertex: ";
    cin >> start;
    for(int i=1;i<=n;i++)
    {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    for(int count=1; count<n; count++)
    {
        int u = -1;
        int minimum = 9999;
        for(int i=1;i<=n;i++)
        {
            if(visited[i] == 0 && dist[i] < minimum)
            {
                minimum = dist[i];
                u = i;
            }
        }
        visited[u] = 1;
        for(int v=1; v<=n; v++)
        {
            if(visited[v] == 0 && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }
    cout << "\nShortest distances from start:\n";
    for(int i=1;i<=n;i++)
        cout << start << " -> " << i << " = " << dist[i] << endl;
    return 0;
}

