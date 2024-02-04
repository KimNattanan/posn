#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back

/*

Problem:
    shortest path S -> X[i] -> T
    for  1 <= i <= Q

*/

vector<pii> adj[100005];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int d1[100005],d2[100005];

void dijk(int d[]){
    while(!pq.empty()){
        int u=pq.top().s;
        int w=pq.top().f;
        pq.pop();
        if(d[u]<w) continue;
        for(auto &vw:adj[u]){
            if(d[vw.f]>w+vw.s){
                d[vw.f]=w+vw.s;
                pq.push({d[vw.f],vw.f});
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
    
    memset(d1,0x3f,sizeof d1);
    memset(d2,0x3f,sizeof d2);
    d1[S]=d2[T]=0;
    pq.push({0,S}),dijk(d1);
    pq.push({0,T}),dijk(d2);

    int Q; cin>>Q;
    while(Q--){
        int x; cin>>x;
        cout<<d1[x]+d2[x]<<endl;
    }

    return 0;
}
