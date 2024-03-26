#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

vector<int> adj[100005];
bool flag[100005];

void dfs(int u){
    flag[u]=1;
    for(auto &v:adj[u]){
        if(!flag[v]) dfs(v);
    }
}

void bfs(int U){
    queue<int> q;
    q.push(U);
    flag[U]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto &v:adj[u]){
            if(!flag[v]){
                flag[v]=1;
                q.push(v);
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    bfs(1);

    return 0;
}
/*

*/
