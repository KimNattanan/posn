#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    int now=0,mx=-1e9;
    for(int i=1;i<=n;++i){
        int x; cin>>x;
        now=max(now+x,x);
        mx=max(mx,now);
    }
    cout<<mx<<endl;

    return 0;
}
