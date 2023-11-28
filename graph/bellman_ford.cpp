#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

struct E{
    int u,v;
    ll w;
};
vector<E> edge;
ll dist[5005],dist0[5005];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    memset(dist,0x3f,sizeof dist);
    edge.resize(m);
    for(int i=0;i<m;++i) cin>>edge[i].u>>edge[i].v>>edge[i].w;
    int S,T; cin>>S>>T;
    dist[S]=0;
    for(int i=0;i<n-1;++i){
        for(auto &e:edge){
            if(dist[e.v]>dist[e.u]+e.w){
                dist[e.v]=dist[e.u]+e.w;
            }
        }
    }
    for(int i=1;i<=n;++i) dist0[i]=dist[i];
    bool ok=1;
    for(auto &e:edge){
        if(dist[e.v]>dist[e.u]+e.w){
            dist[e.v]=dist[e.u]+e.w;
            ok=0;
        }
    }
    if(!ok){
        cout<<"negative cycle."<<endl;
        for(int i=1;i<=n;++i){
            if(dist[i]!=dist0[i]) cout<<i<<" ";
        }
        cout<<endl;
    }
    else cout<<dist[T]<<endl;

    return 0;
}
/*


*/
