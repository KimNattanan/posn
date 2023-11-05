#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;

struct fenwick2d{
    vector<vector<int>> bit;
    int n,m;
    void init(int n_,int m_){
        n=n_,m=m_;
        bit=vector<vector<int>>(n,vector<int>(m));
    }
    void add(int i_,int j_,int x){
        for(int i=i_;i<n;i+=i&-i){
            for(int j=j_;j<m;j+=j&-j) bit[i][j]+=x;
        }
    }
    int qr(int i_,int j_){
        int res=0;
        for(int i=i_;i>0;i-=i&-i){
            for(int j=j_;j>0;j-=j&-j) res+=bit[i][j];
        }
        return res;
    }
    int qr2(int i0,int j0,int i1,int j1){
        return qr(i1,j1)-qr(i1,j0-1)-qr(i0-1,j1)+qr(i0-1,j0-1);
    }
};
