#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

vector<pii> adj[100005];
struct A{
    int u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
int dist[100005];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    int S,T; cin>>S>>T;
    priority_queue<A> pq;
    pq.push({S,0});
    memset(dist,0x3f,sizeof dist);
    dist[S]=0;
    while(!pq.empty()){
        int u=pq.top().u;
        int w=pq.top().w;
        pq.pop();
        for(auto &vw:adj[u]){
            if(dist[vw.f]>w+vw.s){
                dist[vw.f]=w+vw.s;
                pq.push({vw.f,w+vw.s});
            }
        }
    }
    cout<<dist[T]<<endl;

    return 0;
}
/*

*/
