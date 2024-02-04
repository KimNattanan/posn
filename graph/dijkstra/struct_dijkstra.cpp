#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back

vector<pii> adj[100005];

struct dijkstra{
    vector<int> dist;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dijkstra(int n=0){init(n);}
    void init(int n){dist=vector<int>(n,1e9);}
    void push(int u,int w){pq.emplace(w,u);}
    void run(){
        while(pq.size()){
            auto [w,u]=pq.top();
            pq.pop();
            if(dist[u]<w) continue;
            for(auto &[v,vw]:adj[u]){
                if(dist[v]>w+vw){
                    dist[v]=w+vw;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    int& operator[](const int &i){return dist[i];}
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    int S,T; cin>>S>>T;

    dijkstra g(n+5);
    g[S]=0;
    g.push(S,0);
    g.run();

    cout<<g[T];

    return 0;
}
