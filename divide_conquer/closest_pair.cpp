#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

pii a[200005],a_[200005];

ll f(pii a,pii b){
    return ll(a.f-b.f)*(a.f-b.f) + ll(a.s-b.s)*(a.s-b.s);
}
bool cmpY(const pii &l,const pii &r){
    if(l.s!=r.s) return l.s<r.s;
    return l.f<r.f;
}

ll closest_pair(int l,int r){
    int n=r-l+1;
    if(n==2) return f(a[l],a[r]);
    if(n==3) return min({f(a[l],a[l+1]), f(a[l],a[r]), f(a[l+1],a[r])});
    int mid = l+r>>1;
    ll d = min(closest_pair(l,mid), closest_pair(mid+1,r));
    int m = 0;
    for(int i=l;i<=r;++i){
        if(abs(a[i].f - a[mid].f) <= d) a_[m++] = a[i];
    }
    sort(a_,a_+m,cmpY);
    for(int i=0;i<m;++i){
        for(int j=i+1;j<m;++j){
            if(a_[j].s - a_[i].s >= d) break;
            d = min(d, f(a_[i],a_[j]));
        }
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    for(int i=0;i<n;++i) cin>>a[i].f>>a[i].s;
    sort(a,a+n);
    cout<<closest_pair(0,n-1)<<endl;
}