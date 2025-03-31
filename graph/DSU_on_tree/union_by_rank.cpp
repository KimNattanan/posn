#include<bits/stdc++.h>
using namespace std;

int p[100005],rnk[100005];

int fSet(int u){ return p[u]==u ? u : p[u]=fSet(p[u]); }

bool uSet(int u,int v){
  int U=fSet(u),V=fSet(v);
  if(U==V) return 0;
  if(rnk[U]>rnk[V]) swap(U,V);
  p[U]=V;
  if(rnk[U]==rnk[V]) ++rnk[V];
  return 1;
}
