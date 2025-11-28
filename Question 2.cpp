#include <iostream>
using namespace std;

int V, g[100][100], vis[100];

void dfs(int x) {
    vis[x] = 1;
    cout << x << " ";
    for (int i = 0; i < V; i++)
        if (g[x][i] && !vis[i])
            dfs(i);
}

int main() {
    int E,u,v;
    cin >> V >> E;
    while (E--) cin >> u >> v, g[u][v] = g[v][u] = 1;
    dfs(0);
}
