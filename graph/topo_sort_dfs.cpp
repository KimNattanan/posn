#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second

vector<int> adj[100005];
int deg[100005];
vector<int> ans;

void dfs(int u){
    ans.pb(u);
    for(auto &v:adj[u]){
        if(--deg[v]==0) dfs(v);
    }
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        ++deg[v];
    }
    for(int i=1;i<=n;++i){
        if(deg[i]==0) dfs(i);
    }
    if(ans.size()==n) cout<<"cycle"<<endl;
    else{
        for(auto &e:ans) cout<<e<<" ";
        cout<<endl;
    }

    return 0;
}
/*

*/
