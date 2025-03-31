#include<bits/stdc++.h>
using namespace std;

int p[100005],sz[100005];

int fSet(int u){ return p[u]==u ? u : p[u]=fSet(p[u]); }

bool uSet(int u,int v){
  int U=fSet(u),V=fSet(v);
  if(U==V) return 0;
  if(sz[U]>sz[V]) swap(U,V);
  p[U]=V;
  sz[V]+=sz[U];
  return 1;
}
