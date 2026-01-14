#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second
#define eb emplace_back

int p[200005];
int fSet(int u){ return p[u]==u ? u : p[u]=fSet(p[u]); }

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    vector<pair<int,pii>> edge(m); // {w, {u, v}}
    for(auto &e:edge) cin>>e.s.f>>e.s.s>>e.f; // u, v, w
    iota(p,p+n+1,0);
    sort(edge.begin(),edge.end());
    int ans=0;
    for(auto &e:edge){
        int U=fSet(e.s.f), V=fSet(e.s.s);
        if(U==V) continue;
        ans+=e.f;
        p[U]=V;
    }
    cout<<ans;
}
