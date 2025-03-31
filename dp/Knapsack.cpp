#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define eb emplace_back

ll w[1005],val[1005],dp[1005][1005],dp2[2][1005],dp3[1005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n,W; cin>>n>>W;
  for(int i=1;i<=n;++i) cin>>w[i]>>val[i];
  

  {
    for(int i=1;i<=W;++i) dp[0][i]=-1e9;
    for(int i=1;i<=n;++i){
      for(int j=w[i];j<=W;++j){
        dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+val[i]);
      }
    }
  }


  {
    for(int i=1;i<=W;++i) dp2[0][i]=-1e9;
    for(int i=1;i<=n;++i){
      for(int j=w[i];j<=W;++j){
        dp2[i&1][j]=max(dp2[~i&1][j], dp2[~i&1][j-w[i]]+val[i]);
      }
    }
  }


  {
    for(int i=1;i<=W;++i) dp3[i]=-1e9;
    for(int i=1;i<=n;++i){
      for(int j=W;j>=w[i];--j){
        dp3[j]=max(dp3[j], dp3[j-w[i]]+val[i]);
      }
    }
  }
}
