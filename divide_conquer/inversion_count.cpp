#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int a[200005],a_[200005];

ll inv_count(int l,int r){
  if(l==r) return 0;
  int mid=l+r>>1;
  ll res=inv_count(l,mid)+inv_count(mid+1,r);
  for(int il=l, ir=mid+1, i=l; i<=r;){
    if(il>mid) a_[i++]=a[ir++];
    else if(ir>r) a_[i++]=a[il++];
    else if(a[il]>a[ir]) res += mid-il+1, a_[i++]=a[ir++];
    else a_[i++]=a[il++];
  }
  for(int i=l;i<=r;++i) a[i]=a_[i];
  return res;
}
