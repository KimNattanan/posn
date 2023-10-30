#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define ll long long

vector<int> adj[100005];
int disc[100005],low[100005],id0;
stack<int> st;
bool inst[100005];
int comp[100005],id1;
void dfs(int u){
    disc[u]=low[u]=++id0;
    st.push(u);
    inst[u]=1;
    for(auto &v:adj[u]){
        if(!disc[v]) dfs(v),low[u]=min(low[u],low[v]);
        else if(inst[v]) low[u]=min(low[u],low[v]);
    }
    if(low[u]==disc[u]){
        comp[u]=++id1;
        while(st.top()!=u){
            int v=st.top();
            st.pop();
            comp[v]=id1;
            inst[v]=0;
        }
        inst[u]=0;
        st.pop();
    }
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
    }
    for(int i=1;i<=n;++i){
        if(!disc[i]) dfs(i);
    }

    return 0;
}
