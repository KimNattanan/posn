#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[1000005],dp[1000005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  for(int i=1;i<=n;++i) dp[i] = max(a[i], dp[i-1]+a[i]);
}
