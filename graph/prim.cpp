#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define ll long long

ll dist[5005];
ll f(pii a,pii b){
    return 1LL*(a.f-b.f)*(a.f-b.f)+1LL*(a.s-b.s)*(a.s-b.s);
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    vector<pii> vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i].f>>vec[i].s;
    }
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    ll ans=0;
    for(int i=1;i<n;++i){
        ll w=LLONG_MAX;
        int v;
        for(int j=i;j<n;++j){
            dist[j]=min(dist[j],f(vec[i-1],vec[j]));
            if(dist[j]<w){
                w=dist[j];
                v=j;
            }
        }
        ans+=w;
        swap(vec[i],vec[v]);
        swap(dist[i],dist[v]);
        dist[i]=0;
    }
    cout<<ans<<endl;

    return 0;
}
/*

5
1 1
4 6
2 2
3 2
5 1
==25

*/
