#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

int a[5005][5005];
int dp[5005][5005];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int mi,mj; cin>>mi>>mj;
    for(int i=1;i<=mi;++i){
        for(int j=1;j<=mj;++j){
            cin>>a[i][j];
            dp[i][j]=a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    int i0,j0,i1,j1;
    cout<<dp[i1][j1]-dp[i0-1][j1]-dp[i1][j0-1]+dp[i0-1][j0-1];

    return 0;
}
