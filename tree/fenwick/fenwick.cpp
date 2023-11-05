#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;

struct fenwick{
    vector<int> bit;
    int n;
    void init(int n_){
        n=n_;
        bit=vector<int>(n);
    }
    void add(int i,int x){
        for(;i<n;i+=i&-i) bit[i]+=x;
    }
    int qr(int i){
        int res=0;
        for(;i>0;i-=i&-i) res+=bit[i];
        return res;
    }
};
