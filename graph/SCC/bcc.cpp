#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back

vector<int> adj[1000005];

struct BCC{
  int disc[1000005],low[1000005],id;
  bitset<1000005> ap;
  stack<int> st;
  vector<vector<int>> comp;
  void tarj(int u,int p){
    disc[u]=low[u]=++id;
    st.emplace(u);
    for(auto &v:adj[u]) if(v!=p){
      if(!disc[v]){
        tarj(v,u);
        if(low[v]>=disc[u]){
          ap[u] = (p!=-1 || low[v]!=disc[u]);
          comp.eb(vector<int>{u});
          while(comp.back().back()!=v) comp.back().eb(st.top()), st.pop();
        }
        else low[u] = min(low[u], low[v]);
      }
      else low[u] = min(low[u],disc[v]);
    }
  }
  void init(){
    tarj(0,-1);
  }
}bcc;