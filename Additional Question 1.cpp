#include <iostream>
using namespace std;

int V, g[100][100], vis[100];

void dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < V; i++)
        if (g[x][i] && !vis[i])
            dfs(i);
}

int main() {
    int E, u, v;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    int count = 0;

    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i), count++;

    cout << count;
}
