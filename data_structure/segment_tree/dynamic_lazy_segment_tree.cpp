#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define sz(x) (int)x.size()
#define eb emplace_back

struct Segment{
  using A=array<ll,3>;
  A t;
  ll lz;
  vector<Segment> ch;
  int il,ir;
  Segment(int l,int r):il(l),ir(r),t(A{0,0,0}),lz(0){}
  A calc(A l,A r){
    return { l[0]+r[0], min(l[1],r[1]), max(l[2],r[2]) };
  }
  void flush(){
    if(il!=ir){
      if(ch.empty()) ch.eb(il,il+ir>>1), ch.eb((il+ir>>1)+1,ir);
      ch[0].lz+=lz, ch[1].lz+=lz;
    }
    t[0]+=lz, t[1]+=lz, t[2]+=lz;
    lz=0;
  }
  void upd(int l,int r,ll x){
    flush();
    if(il>r||ir<l) return;
    if(l<=il&&ir<=r) return lz+=x, flush();
    ch[0].upd(l,r,x), ch[1].upd(l,r,x);
    t=calc(ch[0].t, ch[1].t);
  }
  A qr(int l,int r){
    flush();
    if(il>r||ir<l) return { 0, 1e18, -1e18 };
    if(l<=il&&ir<=r) return t;
    return calc(ch[0].qr(l,r),ch[1].qr(l,r));
  }
  int ub(ll x){
    flush();
    if(t[0]<=x) return ir+1;
    if(il==ir) return il;
    ch[0].flush();
    if(ch[0].t[0]>x) return ch[0].ub(x);
    return ch[1].ub(x-ch[0].t[0]);
  }
}t;
