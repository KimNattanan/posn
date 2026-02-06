// programming - a-point
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define eb emplace_back

ll a[605],qs[605],dp[605][605];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin>>n;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    qs[i] = a[i]+qs[i-1];
  }
  for(int k=2;k<=n;++k){
    for(int l=1,r=k;r<=n;++l,++r){
      for(int i=l;i<r;++i){
        ll mn = min(qs[i]-qs[l-1], qs[r]-qs[i]);
        ll mx = max(qs[i]-qs[l-1], qs[r]-qs[i]);
        dp[l][r] = max(dp[l][r], dp[l][i] + dp[i+1][r] + 2*mn+mx);
      }
    }
  }
  cout<<dp[1][n]<<'\n';
}