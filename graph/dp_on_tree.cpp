#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second

vector<pii> adj[100005];
int sum[100005];
void dfs(int u,int p){
    sum[u]=0; // base case
    for(auto &vw:adj[u]){
        if(vw.f!=p){
            dfs(vw.f,u);
            sum[u]+=vw.s+sum[vw.f];
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    for(int i=0;i<n-1;++i){
        int u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dfs(1,1);

    return 0;
}
/*

*/
