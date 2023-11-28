#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

vector<int> adj[100005];
int deg[100005];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        ++deg[v];
    }
    queue<int> q;
    for(int i=1;i<=n;++i){
        if(deg[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.pb(u);
        for(auto &v:adj[u]){
            if(--deg[v]==0) q.push(v);
        }
    }
    if(ans.size()!=n) cout<<"cycle"<<endl;
    else{
        for(auto &e:ans) cout<<e<<" ";
        cout<<endl;
    }

    return 0;
}
/*

*/
