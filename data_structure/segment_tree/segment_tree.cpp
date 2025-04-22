#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define sz(x) (int)x.size()

ll a[200005];

struct Segment{
  using A=array<ll,3>;
  A t[1<<19]; // lowest k  of which  2^k >= 2*n
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
  void upd(int i,int il,int ir,int id,ll x){
    if(il==ir) return void(t[i][0]=t[i][1]=t[i][2]+=x);
    int mid=il+ir>>1;
    if(id<=mid) upd(i<<1,il,mid,id,x);
    else upd(i<<1|1,mid+1,ir,id,x);
    t[i] = calc(t[i<<1], t[i<<1|1]);
  }
  void upd(int id,ll x){ upd(1,l0,r0,id,x); }
  A qr(int i,int il,int ir,int l,int r){
    if(il>r||ir<l) return {0, 1e18, -1e18};
    if(l<=il&&ir<=r) return t[i];
    int mid=il+ir>>1;
    return calc(qr(i<<1,il,mid,l,r), qr(i<<1|1,mid+1,ir,l,r));
  }
  A qr(int l,int r){ return qr(1,l0,r0,l,r); }
  int ub(int i,int il,int ir,ll x){
    if(t[i][0]<=x) return ir+1;
    if(il==ir) return il;
    int mid=il+ir>>1;
    if(t[i<<1][0]>x) return ub(i<<1,il,mid,x);
    return ub(i<<1|1,mid+1,ir,x-t[i<<1][0]);
  }
  int ub(ll x){ return ub(1,l0,r0,x); }
}t;
