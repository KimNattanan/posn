#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<pair<int,ll>> adj[100005];
ll d[100005];
using A=pair<ll,int>;
priority_queue<A,vector<A>,greater<A>> pq;

void dijk(){
  while(!pq.empty()){
    auto [w,u]=pq.top(); pq.pop();
    if(d[u]!=w) continue;
    for(auto &[v,vw]:adj[u]) if(d[v]>w+vw){
      d[v]=w+vw;
      pq.emplace(d[v],v);
    }
  }
}
