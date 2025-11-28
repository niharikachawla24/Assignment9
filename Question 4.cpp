#include <iostream>
using namespace std;

int main() {
    int V,E,u,v,w;
    cin >> V >> E;

    int g[100][100];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            g[i][j] = 0;

    while(E--) cin >> u >> v >> w, g[u][v] = w;

    int dist[100], used[100]={0};
    for(int i=0;i<V;i++) dist[i] = 1e9;
    dist[0] = 0;

    for(int i=0;i<V;i++){
        int mn = 1e9, x = -1;
        for(int j=0;j<V;j++)
            if(!used[j] && dist[j] < mn)
                mn = dist[j], x = j;

        used[x] = 1;

        for(int j=0;j<V;j++)
            if(g[x][j] && dist[x] + g[x][j] < dist[j])
                dist[j] = dist[x] + g[x][j];
    }

    for(int i=0;i<V;i++) cout << dist[i] << " ";
}
