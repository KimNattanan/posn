#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=1e18;

ll d[505][505];
bitset<505> negative_cycle;

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n,m; cin>>n>>m;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j) d[i][j]=inf;
    d[i][i]=0;
  }
  for(int i=0;i<m;++i){
    int u,v,w; cin>>u>>v>>w;
    d[u][v]=min(d[u][v],(ll)w);
    // d[u][v]=d[v][u]=min(d[u][v],(ll)w); // bidirectional graph
  }
  for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
    if(d[i][k]!=inf && d[k][j]!=inf) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  }
  for(int i=1;i<=n;++i) negative_cycle[i] = (d[i][i]<0);
}
