#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define ll long long

vector<int> adj[100005];
int tour[100005],ed[100005],id0;
void dfs(int u,int p){
    tour[u]=++id0;
    for(auto &v:adj[u]){
        if(v!=p) dfs(v,u);
    }
    ed[u]=id0;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    for(int i=0;i<n-1;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1);

    return 0;
}
/*


*/
