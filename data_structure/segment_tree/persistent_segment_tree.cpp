#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define sz(x) (int)x.size()
#define eb emplace_back

struct Segment{
  using A=array<ll,3>;
  struct node{
    node *l,*r;
    A v;
    node(ll x=0):v(A{x,x,x}),l(nullptr),r(nullptr){}
  };
  using pnode=node*;
  vector<pnode> rt;
  int l0,r0;
  void init(int n,int l,int r){
    l0=l, r0=r;
    rt.resize(n);
    build(rt[0],l0,r0);
  }
  void build(pnode &t,int il,int ir){
    t=new node();
    if(il==ir) return;
    int mid=il+ir>>1;
    build(t->l,il,mid), build(t->r,mid+1,ir);
  }
  A calc(A l,A r){
    return { l[0]+r[0], min(l[1],r[1]), max(l[2],r[2]) };
  }
  void upd(pnode t0,pnode &t1,int il,int ir,int id,ll x){
    t1=new node(*t0);
    if(il==ir) return void(t1->v[0]=t1->v[1]=t1->v[2]+=x);
    int mid=il+ir>>1;
    if(id<=mid) upd(t0->l,t1->l,il,mid,id,x);
    else upd(t0->r,t1->r,mid+1,ir,id,x);
    t1->v=calc(t1->l->v,t1->r->v);
  }
  void upd(int t0,int t1,int id,ll x){ upd(rt[t0],rt[t1],l0,r0,id,x); }
  A qr(pnode t,int il,int ir,int l,int r){
    if(il>r||ir<l) return {0,1e18,-1e18};
    if(l<=il&&ir<=r) return t->v;
    int mid=il+ir>>1;
    return calc(qr(t->l,il,mid,l,r),qr(t->r,mid+1,ir,l,r));
  }
  A qr(int t,int l,int r){ return qr(rt[t],l0,r0,l,r); }
  ll qr2(pnode t0,pnode t1,int il,int ir,int l,int r){
    if(il>r||ir<l) return 0;
    if(l<=il&&ir<=r) return t1->v[0] - t0->v[0];
    int mid=il+ir>>1;
    return qr2(t0->l,t1->l,il,mid,l,r) + qr2(t0->r,t1->r,mid+1,ir,l,r);
  }
  ll qr2(int t0,int t1,int l,int r){ return qr2(rt[t0],rt[t1],l0,r0,l,r); }
  int ub(pnode t,int il,int ir,ll x){
    if(t->v[0]<=x) return ir+1;
    if(il==ir) return il;
    int mid=il+ir>>1;
    ll suml = t->l->v[0];
    if(suml>x) return ub(t->l,il,mid,x);
    return ub(t->r,mid+1,ir, x-suml);
  }
  int ub(int t,ll x){ return ub(rt[t],l0,r0,x); }
  int ub2(pnode t0,pnode t1,int il,int ir,ll x){
    if(t1->v[0]-t0->v[0]<=x) return ir+1;
    if(il==ir) return il;
    int mid=il+ir>>1;
    ll suml = t1->l->v[0] - t0->l->v[0];
    if(suml>x) return ub2(t0->l,t1->l,il,mid,x);
    return ub2(t0->r,t1->r,mid+1,ir,x-suml);
  }
  int ub2(int t0,int t1,ll x){ return ub2(rt[t0],rt[t1],l0,r0,x); }
}t;
