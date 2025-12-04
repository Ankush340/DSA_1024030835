#include <iostream>
using namespace std;
int parent[20];
int find(int x)
{
    while(parent[x] != x)
        x = parent[x];
    return x;
}
void union_set(int a, int b)
{
    parent[b] = a;
}
int main()
{
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    int u[20], v[20], w[20];
    cout << "Enter edges (u v w):\n";
    for(int i=1;i<=e;i++)
        cin >> u[i] >> v[i] >> w[i];
    for(int i=1;i<=n;i++)
        parent[i] = i;
    for(int i=1;i<=e;i++)
        for(int j=i+1;j<=e;j++)
            if(w[i] > w[j])
            {
                int t;
                t = w[i]; w[i] = w[j]; w[j] = t;
                t = u[i]; u[i] = u[j]; u[j] = t;
                t = v[i]; v[i] = v[j]; v[j] = t;
            }
    int cost = 0;
    cout << "\nEdges in MST:\n";
    for(int i=1;i<=e;i++)
    {
        int a = find(u[i]);
        int b = find(v[i]);
        if(a != b)
        {
            cout << u[i] << " - " << v[i] << "  cost = " << w[i] << endl;
            cost += w[i];
            union_set(a,b);
        }
    }
    cout << "\nTotal Minimum Cost = " << cost << endl;
    return 0;
}

