#include <iostream>
using namespace std;
int main()
{
    int n;
    int cost[20][20];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter cost adjacency matrix (0 for no edge):\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> cost[i][j];
    int visited[20];
    for(int i=1;i<=n;i++)
        visited[i]=0;
    visited[1] = 1;
    int edges = 0;
    int minCost = 0;
    cout << "\nMinimum Spanning Tree edges:\n";
    while(edges < n-1)
    {
        int u = -1, v = -1;
        int minimum = 9999;
        for(int i=1;i<=n;i++)
        {
            if(visited[i] == 1)
            {
                for(int j=1;j<=n;j++)
                {
                    if(visited[j] == 0 && cost[i][j] < minimum && cost[i][j] != 0)
                    {
                        minimum = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v] = 1;
        cout << u << " - " << v << "  cost = " << minimum << endl;
        minCost += minimum;
        edges++;
    }
    cout << "\nTotal Minimum Cost = " << minCost << endl;
    return 0;
}

