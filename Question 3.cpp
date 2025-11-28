//Kruskal
#include <iostream>
using namespace std;

int p[100], sz[100];

int findp(int x){
    return p[x]==x ? x : p[x]=findp(p[x]);
}

bool unite(int a,int b){
    a=findp(a); b=findp(b);
    if(a==b) return false;
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a; sz[a]+=sz[b];
    return true;
}

int main(){
    int V,E;
    cin>>V>>E;

    int u[500], v[500], w[500];
    for(int i=0;i<E;i++) cin>>u[i]>>v[i]>>w[i];

    for(int i=0;i<V;i++) p[i]=i, sz[i]=1;

    for(int i=0;i<E;i++)
        for(int j=i+1;j<E;j++)
            if(w[j]<w[i]){
                swap(w[i],w[j]);
                swap(u[i],u[j]);
                swap(v[i],v[j]);
            }

    int mst=0;
    for(int i=0;i<E;i++)
        if(unite(u[i],v[i]))
            mst+=w[i];

    cout<<mst;
}

