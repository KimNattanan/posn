#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define ll long long

int P[100005],sz[100005];

int fSet(int u){
    if(P[u]==u) return u;
    return fSet(P[u]);
}

bool uSet(int u,int v){
    int U=fSet(u),V=fSet(v);
    if(U==V) return 0;
    if(sz[U]>sz[V]) swap(U,V);
    P[U]=V;
    sz[V]+=sz[U];
    return 1;
}
