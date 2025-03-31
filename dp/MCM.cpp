#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// https://beta.programming.in.th/tasks/codecube_025

ll a[605],qs[605],dp[605][605];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i], qs[i]=qs[i-1]+a[i];
  for(int k=1;k<=n;++k){
    for(int l=1,r=k; r<=n; ++l,++r){
      if(k==1) dp[l][r]=0;
      else{
        dp[l][r]=0;
        for(int i=l;i<r;++i){
          ll cost = qs[r]-qs[l-1] + min(qs[i]-qs[l-1], qs[r]-qs[i]);
          dp[l][r] = max(dp[l][r], dp[l][i]+dp[i+1][r] + cost);
        }
      }
    }
  }
  cout << dp[1][n];
}
