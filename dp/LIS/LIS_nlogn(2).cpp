#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back

int dp[100005];

vector<int> LIS(vector<int> &vec){
  vector<vector<int>> temp(vec.size());
  int sz=0;
  for(auto &e:vec){
    int id=lower_bound(dp,dp+sz,e)-dp;
    if(id==sz) ++sz;
    dp[id]=e;
    temp[id].eb(e);
  }
  
  int now=temp[sz-1][0];
  vector<int> ret;
  ret.eb(now);
  for(sz-=2;sz>=0;--sz){
    now=*lower_bound(temp[sz].begin(),temp[sz].end(),now,greater<int>());
    ret.eb(now);
  }
  reverse(ret.begin(),ret.end());
  return ret;
}
