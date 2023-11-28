#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back

double f(pii a,pii b){
    return sqrt(1LL*(a.f-b.f)*(a.f-b.f)+1LL*(a.s-b.s)*(a.s-b.s));
}
bool cmpY(const pii &l,const pii &r){
    if(l.s!=r.s) return l.s<r.s;
    return l.f<r.f;
}

double play(vector<pii> &vec){
    int n=vec.size();
    if(n==2) return f(vec[0],vec[1]);
    if(n==3) return min({f(vec[0],vec[1]),f(vec[0],vec[2]),f(vec[1],vec[2])});
    vector<pii> L,R,M;
    for(int i=0;i<n/2;++i) L.pb(vec[i]);
    for(int i=n/2;i<n;++i) R.pb(vec[i]);
    double d=min(play(L),play(R));
    for(auto &e:vec){
        if(abs(e.f-vec[n/2].f)<=d) M.pb(e);
    }
    sort(M.begin(),M.end(),cmpY);
    for(int i=0;i<M.size();++i){
        for(int j=0;j<M.size();++j){
            if(M[j].s-M[i].s>=d) break;
            d=min(d,f(M[i],M[j]));
        }
    }
    return d;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    vector<pii> vec(n);
    for(auto &e:vec) cin>>e.f>>e.s;
    sort(vec.begin(),vec.end());
    cout<<play(vec)<<endl;

    return 0;
}
/**

*/