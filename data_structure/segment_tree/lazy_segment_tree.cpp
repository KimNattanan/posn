#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define sz(x) (int)x.size()

ll a[200005];

struct Segment{
  using A=array<ll,3>;
  A t[1<<19]; // lowest k  for which  2^k >= 2*n
  ll lz[1<<19];
  int l0,r0;
  void init(int l,int r){ l0=l, r0=r, build(1,l0,r0); }
  A calc(A tl,A tr){
    return {
      tl[0] + tr[0],
      min(tl[1], tr[1]),
      max(tl[2], tr[2])
    };
  }
  void build(int i,int il,int ir){
    if(il==ir) return void(t[i][0]=t[i][1]=t[i][2]=a[il]);
    int mid=il+ir>>1;
    build(i<<1,il,mid), build(i<<1|1,mid+1,ir);
    t[i] = calc(t[i<<1],t[i<<1|1]);
  }
  void flush(int i,int il,int ir){
    if(il!=ir) lz[i<<1]+=lz[i], lz[i<<1|1]+=lz[i];
    t[i][0]+=lz[i];
    t[i][1]+=lz[i];
    t[i][2]+=lz[i];
    lz[i]=0;
  }
  void upd(int i,int il,int ir,int l,int r,ll x){
    flush(i,il,ir);
    if(il>r||ir<l) return;
    if(l<=il&&ir<=r) return lz[i]+=x, flush(i,il,ir);
    int mid=il+ir>>1;
    upd(i<<1,il,mid,l,r,x), upd(i<<1|1,mid+1,ir,l,r,x);
    t[i] = calc(t[i<<1], t[i<<1|1]);
  }
  void upd(int l,int r,ll x){ upd(1,l0,r0,l,r,x); }
  A qr(int i,int il,int ir,int l,int r){
    flush(i,il,ir);
    if(il>r||ir<l) return {0, 1e18, -1e18};
    if(l<=il&&ir<=r) return t[i];
    int mid=il+ir>>1;
    return calc(qr(i<<1,il,mid,l,r), qr(i<<1|1,mid+1,ir,l,r));
  }
  A qr(int l,int r){ return qr(1,l0,r0,l,r); }
  int ub(int i,int il,int ir,ll x){
    flush(i,il,ir);
    if(t[i][0]<=x) return ir+1;
    if(il==ir) return il;
    int mid=il+ir>>1;
    flush(i<<1,il,mid);
    if(t[i<<1][0]>x) return ub(i<<1,il,mid,x);
    return ub(i<<1|1,mid+1,ir,x-t[i<<1][0]);
  }
  int ub(ll x){ return ub(1,l0,r0,x); }
}t;
