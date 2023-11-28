#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back

int w[2005],val[2005];
int dp[10005];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>w[i]>>val[i];
    
    for(int i=1;i<=n;++i){
        for(int j=k;j>=1;--j){
            dp[j]=max(dp[j],dp[j-1]);
            if(j>=w[i]) dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
        }
    }
    
    return 0;
}