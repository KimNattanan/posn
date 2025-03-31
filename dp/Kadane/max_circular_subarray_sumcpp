#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[1000005],dp[1000005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  for(int i=1;i<=n;++i) dp[i] = max(a[i], dp[i-1]+a[i]);
  ll mn=0,mx=0,sum=0;
  for(int i=1;i<=n;++i) mn=min(mn,dp[i]), mx=max(mx,dp[i]), sum+=a[i];
  ll ans = max(mx, sum-mn);
  cout << ans;
}
