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
ll closest_pair(vector<pii> &vx,vector<pii> &vy){
    int n=vx.size();
    if(n==2) return f(vx[0],vx[1]);
    if(n==3) return min({f(vx[0],vx[1]),f(vx[0],vx[2]),f(vx[1],vx[2])});

    int mid=n>>1;
    vector<pii> vxL,vxR,vyL,vyR;
    for(int i=0;i<mid;++i) vxL.push_back(vx[i]);
    for(int i=mid;i<n;++i) vxR.push_back(vx[i]);
    for(auto &e:vy){
        if(e < vx[mid]) vyL.push_back(e);
        else vyR.push_back(e);
    }
    
    ll d=min(closest_pair(vxL,vyL),closest_pair(vxR,vyR));
    vector<pii> vM;
    for(auto &e:vy){
        if(1LL*(e.f-vx[mid].f)*(e.f-vx[mid].f) < d) vM.push_back(e);
    }
    for(int i=0;i<vM.size();++i){
        for(int j=i+1;j<vM.size();++j){
            if(1LL*(vM[j].s-vM[i].s)*(vM[j].s-vM[i].s) >= d) break;
            d=min(d,f(vM[i],vM[j]));
        }
    }

    return d;
}
