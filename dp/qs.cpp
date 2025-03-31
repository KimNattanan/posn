#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[100005],qsa[100005],b[1005][1005],qsb[1005][1005];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int n,m;
  for(int i=1;i<=n;++i) cin>>a[i], qsa[i]=a[i]+qsa[i-1];
  for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
    cin>>b[i][j];
    qsb[i][j] = b[i][j] + qsb[i-1][j] + qsb[i][j-1] - qsb[i-1][j-1];
  }
}
