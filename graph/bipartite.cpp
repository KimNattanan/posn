#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

vector<int> adj[100005];
int color[100005];
bool dfs(int u,int c){
    color[u]=c;
    for(auto &v:adj[u]){
        if(color[v]==c) return 0;
        if(color[v]==0 && !dfs(v,c^3)) return 0;
    }
    return 1;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(dfs(1,1)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    return 0;
}
/*

4 4
1 2
2 3
3 4
1 4
=yes


4 4
1 2
2 3
3 4
1 3
=no

*/
