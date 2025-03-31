#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()

bool dp[2005][2005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  string s; cin>>s;
  for(int i=1;i<=sz(s);++i) dp[i][i]=1;
  for(int k=2;k<=sz(s);++k){
    for(int l=0,r=k-1;r<=sz(s);++l,++r){
      dp[l][r] = (s[l]==s[r] && (k==2 || dp[l+1][r-1]));
    }
  }
}
