#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define sz(x) (int)x.size()

struct Fenwick{
  vector<ll> bit;
  void init(int n){ bit.assign(n,0); }
  void upd(int i,ll x){ for(;i<sz(bit); i+=i&-i) bit[i]+=x; }
  ll qr(int i){
    ll res=0;
    for(;i>0;i-=i&-i) res+=bit[i];
    return res;
  }
  int ub(ll x){ // lowest i  of which  sum(1->i) > x
    int pos=0;
    ll sum=0;
    for(int i=1<<31-__builtin_clz(sz(bit));i>0;i>>=1){
      if(pos+i<sz(bit) && sum+bit[pos+i] <= x) sum += bit[pos+=i];
    }
    return pos+1;
  }
}fw;
