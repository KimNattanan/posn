#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back

int inv_cnt(vector<int> &vec){
    int n=vec.size();
    if(n==1) return 0;
    vector<int> L,R;
    for(int i=0;i<n/2;++i) L.pb(vec[i]);
    for(int i=n/2;i<n;++i) R.pb(vec[i]);
    int ans=inv_cnt(L)+inv_cnt(R);
    vec.clear();
    int l=0,r=0;
    while(l<L.size()&&r<R.size()){
        if(L[l]>R[r]){
            ans+=(L.size()-l);
            vec.pb(R[r++]);
        }
        else{
            vec.pb(L[l++]);
        }
    }
    while(l<L.size()) vec.pb(L[l++]);
    while(r<R.size()) vec.pb(R[r++]);
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    cout<<inv_cnt(vec)<<endl;

    return 0;
}
/**

*/