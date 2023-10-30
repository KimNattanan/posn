#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second

int P[100005];
int fSet(int u){
    if(P[u]==u) return u;
    return P[u]=fSet(P[u]);
}

struct E{
    int u,v,w;
    bool operator<(const E&o)const{
        return w<o.w;
    }
};
vector<E> edge;

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v,w; cin>>u>>v>>w;
        edge.pb({u,v,w});
    }
    for(int i=1;i<=n;++i) P[i]=i;
    sort(edge.begin(),edge.end());
    int ans=0;
    for(auto &e:edge){
        int U=fSet(e.u),V=fSet(e.v);
        if(U==V) continue;
        ans+=e.w;
        P[U]=V;
    }
    cout<<ans<<endl;

    return 0;
}
