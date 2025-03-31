#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define sz(x) (int)x.size()
#define eb emplace_back

struct Segment{
  using A=array<ll,3>;
  A t;
  vector<Segment> ch;
  int il,ir;
  Segment(int l,int r):il(l),ir(r),t(A{0,0,0}){}
  A calc(A l,A r){
    return { l[0]+r[0], min(l[1],r[1]), max(l[2],r[2]) };
  }
  void flush(){
    if(il!=ir && ch.empty()) ch.eb(il,il+ir>>1), ch.eb((il+ir>>1)+1,ir);
  }
  void upd(int id,ll x){
    flush();
    if(il==ir) return void(t[0]=t[1]=t[2]+=x);
    int mid=il+ir>>1;
    if(id<=mid) ch[0].upd(id,x);
    else ch[1].upd(id,x);
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
    if(ch[0].t[0]>x) return ch[0].ub(x);
    return ch[1].ub(x-ch[0].t[0]);
  }
}t;
