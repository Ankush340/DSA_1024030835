#include <iostream>
using namespace std;
int adj[20][20];
int visited[20];
int q[20];
int main()
{
    int n, e, start;
    int front = 0, rear = -1;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            adj[i][j] = 0;
    cout << "Enter edges (u v):\n";
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    cout << "Enter start vertex: ";
    cin >> start;
    for(int i = 1; i <= n; i++)
        visited[i] = 0;
    cout << "\nBFS Traversal: ";
    visited[start] = 1;
    q[++rear] = start;
    while(front <= rear)
    {
        int u = q[front++];
        cout << u << " ";
        for(int v = 1; v <= n; v++)
        {
            if(adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[++rear] = v;
            }
        }
    }
    cout << endl;
    return 0;
}

