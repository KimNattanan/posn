#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bitset<100005> vis;
int d[100005];
queue<int> q;

void dfs(int u){
  vis[u]=1;
  for(auto &v:adj[u]) if(!vis[v]){
    d[v]=d[u]+1;
    dfs(v);
  }
}

void bfs(int u){
  vis[u]=1;
  d[u]=0;
  q.emplace(u);
  while(!q.empty()){
    int u=q.front(); q.pop();
    for(auto &v:adj[u]) if(!vis[v]){
      vis[v]=1;
      d[v]=d[u]+1;
      q.emplace(v);
    }
  }
}
