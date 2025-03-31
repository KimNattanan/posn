#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back

int a[100005],dp[100005],dp2[100005],lis[100005];
vector<int> hist[100005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  int sz=0;
  for(int i=1;i<=n;++i){
    int id=lower_bound(dp,dp+sz,a[i])-dp;     // a[l] < a[r]
    // int id=upper_bound(dp,dp+sz,a[i])-dp;  // a[l] <= a[r]
    if(id==sz) ++sz;
    dp[id]=a[i];
    dp2[i]=sz;
    hist[id].eb(a[i]);
  }
  lis[sz-1]=hist[sz-1][0];
  for(int i=sz-2;i>=0;--i){
    for(auto &e:hist[i]){
      if(e<lis[i+1]){
        lis[i]=e;
        break;
      }
    }
  }
  cout<<sz<<'\n';
  for(int i=0;i<sz;++i) cout<<lis[i]<<" ";
}
