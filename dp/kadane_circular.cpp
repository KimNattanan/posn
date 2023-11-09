#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    int now0=0,now1=0,mn=1e9,mx=-1e9,sum=0;
    for(int i=1;i<=n;++i){
        int x; cin>>x;
        sum+=x;
        now0=max(now0+x,x),mx=max(mx,now0);
        if(i>1) now1=min(now1+x,x),mn=min(mn,now1);
    }
    cout<<max(mx,sum-mn)<<endl;

    return 0;
}
