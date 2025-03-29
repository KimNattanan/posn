#include<bits/stdc++.h>
using namespace std;

int a[200005],a_[200005];

ll merge_sort(int l,int r){
  if(l==r) return 0;
  int mid=l+r>>1;
  merge_sort(l,mid), merge_sort(mid+1,r);
  for(int il=l, ir=mid+1, i=l; i<=r;){
    if(il>mid) a_[i++]=a[ir++];
    else if(ir>r) a_[i++]=a[il++];
    else if(a[il]<a[ir]) a_[i++]=a[il++];
    else a_[i++]=a[ir++];
  }
  for(int i=l;i<=r;++i) a[i]=a_[i];
}
