#include<bits/stdc++.h>
using namespace std;

int a[1005],dp[1005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  for(int i=1;i<=n;++i){
    dp[i]=1;
    for(int j=1;j<i;++j) if(a[j]<a[i]) dp[i]=max(dp[i], dp[j]+1);
  }
}
