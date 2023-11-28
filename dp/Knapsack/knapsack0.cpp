#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back

int w[2005],val[2005];
int dp[2005][10005];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>w[i]>>val[i];
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+val[i]);
        }
    }
    
    return 0;
}