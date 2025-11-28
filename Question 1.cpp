#include <iostream>
using namespace std;

int main() {
    int V,E,u,v;
    cin >> V >> E;

    int g[100][100] = {0};
    while (E--) cin >> u >> v, g[u][v] = g[v][u] = 1;

    int vis[100] = {0}, q[100], f = 0, r = 0;
    q[r++] = 0; 
    vis[0] = 1;

    while (f < r) {
        int x = q[f++];
        cout << x << " ";
        for (int i = 0; i < V; i++)
            if (g[x][i] && !vis[i])
                vis[i] = 1, q[r++] = i;
    }
}
