#include<bits/stdc++.h>
using namespace std;

struct fenwick2d{
    vector<vector<int>> bit;
    int n,m;
    fenwick2d(int n_=0,int m_=0){init(n_,m_);}
    void init(int n_,int m_){
        n=n_,m=m_;
        bit=vector<vector<int>>(n,vector<int>(m));
    }
    void upd(int i_,int j_,int x){
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
    void upd(int i0,int j0,int i1,int j1,int x){
        upd(i0,j0,x),upd(i0,j1+1,-x),upd(i1+1,j0,-x),upd(i1+1,j1+1,x);
    }
    int qr(int i0,int j0,int i1,int j1){
        return qr(i1,j1)-qr(i1,j0-1)-qr(i0-1,j1)+qr(i0-1,j0-1);
    }
};
