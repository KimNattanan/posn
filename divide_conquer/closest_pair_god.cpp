#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

ll f(pii l,pii r){
    return 1LL*(l.f-r.f)*(l.f-r.f)+1LL*(l.s-r.s)*(l.s-r.s);
}
ll closest_pair(vector<pii> &vx){
    ll d=LLONG_MAX;
    for(int i=0;i<vx.size();++i){
        for(int j=max(0,i-5);j<i;++j){
            d=min(d,f(vx[i],vx[j]));
        }
    }
    return d;
}
