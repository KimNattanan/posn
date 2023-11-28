#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

int dp[305][305];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m; cin>>n>>m;
    memset(dp,0x3f,sizeof dp);
    for(int i=0;i<m;++i){
        int u,v,w; cin>>u>>v>>w;
        dp[u][v]=dp[v][u]=min(dp[u][v],w);
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    return 0;
}
/*


*/
