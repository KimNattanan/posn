#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()

int dp[5005][5005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  string a,b; cin>>a>>b;
  for(int i=1;i<=sz(a);++i) dp[i][0]=i;
  for(int j=1;j<=sz(b);++j) dp[0][j]=j;
  for(int i=1;i<=sz(a);++i){
    for(int j=1;j<=sz(b);++j){
      if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
      else dp[i][j]=min({ dp[i-1][j],  // delete
                          dp[i][j-1],  // insert
                          dp[i-1][j-1] // change
                        })+1;
    }
  }
	cout<<dp[sz(a)][sz(b)];
}
