#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

int P[100005],rnk[100005];

int fSet(int u){
    if(P[u]==u) return u;
    return fSet(P[u]);
}

bool uSet(int u,int v){
    int U=fSet(u),V=fSet(v);
    if(U==V) return 0;
    if(rnk[U]>rnk[V]) swap(U,V);
    P[U]=V;
    if(rnk[U]==rnk[V]) ++rnk[V];
    return 1;
}
