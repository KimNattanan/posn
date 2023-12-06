#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back

int w[2005],val[2005];
int dp[2][10005];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>w[i]>>val[i];
    
    dp[0][0]=0;
    for(int j=1;j<=k;++j) dp[0][j]=-1e9;

    for(int i=1;i<=n;++i){
        int now=i%2,prev=1-now;
        for(int j=1;j<=k;++j){
            dp[now][j]=dp[prev][j];
            if(j>=w[i]) dp[now][j]=max(dp[now][j],dp[prev][j-w[i]]+val[i]);
        }
    }
    cout<<dp[n%2][k];
    
    return 0;
}
