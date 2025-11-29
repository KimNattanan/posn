#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

using i3=array<int,3>;
vector<i3> edge;
int d[200005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n,m; cin>>n>>m;
  edge.resize(m);
  for(auto &[u,v,w]:edge) cin>>u>>v>>w;
  fill(d,d+n+1,inf);
  
  int s; cin>>s;
  d[s]=0;
  for(int i=0;i<n-1;++i) for(auto &[u,v,w]:edge){
    if(d[u]!=inf) d[v] = min(d[v], d[u]+w);
  }
  bool neg=false;
  for(auto &[u,v,w]:edge) if(d[u]!=inf && d[u]+w < d[v]){
    neg=1;
    break;
  }

}
