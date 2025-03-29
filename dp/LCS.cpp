#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()

int dp[2005][2005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  string a,b; cin>>a>>b;
  for(int i=1;i<=sz(a);++i){
    for(int j=1;j<=sz(b);++j){
      if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  cout<<dp[sz(a)][sz(b)];
}
