#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> adj[100005],rev[100005];
stack<int> st;
int comp[100005],id0;
bool vis[100005];

void dfs0(int u){
    vis[u]=1;
    for(auto &v:adj[u]) if(!vis[v]) dfs0(v);
    st.push(u);
}
void dfs1(int u,int id){
    vis[u]=1;
    comp[u]=id;
    for(auto &v:rev[u]) if(!vis[v]) dfs1(v,id);
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v), rev[v].pb(u);
    }
    for(int i=1;i<=n;++i) if(!vis[i]) dfs0(i);
    memset(vis,0,sizeof vis);
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(!vis[u]) dfs1(u,++id0);
    }
    
    return 0;
}
