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

struct Fenwick2D{
  vector<vector<ll>> bit;
  int n,m;
  void init(int n,int m){ bit.assign(n,vector<ll>(m,0)); }
  void upd(int i0,int j0,ll x){
    for(int i=i0;i<sz(bit);i+=i&-i){
      for(int j=j0;j<sz(bit[0]);j+=j&-j) bit[i][j]+=x;
    }
  }
  ll qr(int i0,int j0){
    ll res=0;
    for(int i=i0;i>0;i-=i&-i){
      for(int j=j0;j>0;j-=j&-j) res+=bit[i][j];
    }
    return res;
  }
}fw2;
