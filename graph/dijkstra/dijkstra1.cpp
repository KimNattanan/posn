#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back

vector<pii> adj[100005];
struct A{
    int u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> pq;
int dist[100005];

void dijk(int d[]){
    while(!pq.empty()){
        int u=pq.top().u;
        int w=pq.top().w;
        pq.pop();
        if(d[u]<w) continue;
        for(auto &vw:adj[u]){
            if(d[vw.f]>w+vw.s){
                d[vw.f]=w+vw.s;
                pq.push({vw.f,d[vw.f]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    int S,T; cin>>S>>T;
    
    memset(dist,0x3f,sizeof dist);
    dist[S]=0;
    pq.push({S,0}),dijk(dist);

    cout<<dist[T]<<endl;

    return 0;
}
