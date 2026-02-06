// yosupo - longest increasing subsequence
#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define f first
#define s second
#define eb emplace_back

int a[500005],dp[500005];
vector<int> vdp[500005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin>>n;
  for(int i=0;i<n;++i) cin>>a[i];
  int ans=0;
  for(int i=0;i<n;++i){
    int id=lower_bound(dp,dp+ans,a[i])-dp;
    if(id==ans) ++ans;
    dp[id]=a[i];
    vdp[id].eb(i);
  }
  vector<int> vans={vdp[ans-1][0]};
  for(int i=ans-2;i>=0;--i){
    for(auto &e:vdp[i]) if(a[e]<a[vans.back()]){
      vans.eb(e);
      break;
    }
  }
  reverse(vans.begin(),vans.end());
  cout<<ans<<'\n';
  for(auto &e:vans) cout<<e<<" ";
}