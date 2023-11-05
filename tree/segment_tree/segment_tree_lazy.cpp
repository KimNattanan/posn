#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;

const int N=1e5;

int arr[N+5];

struct segment{
    vector<segment> child;
    int l,r,mid,sz;
    int sum;
    bool call;
    int lazy;
    segment(int l_=0,int r_=0,int val=0){
        l=l_,r=r_,mid=l+(r-l>>1),sz=r-l+1;
        sum=val*sz;
        call=lazy=0;
    }
    void flush(){
        if(l!=r&&child.empty()){
            child.emplace_back(l,mid,sum/sz);
            child.emplace_back(mid+1,r,sum/sz);
        }
        if(call){
            if(l!=r){
                child[0].call=child[1].call=1;
                child[0].lazy+=lazy;
                child[1].lazy+=lazy;
            }
            sum+=lazy*sz;
            lazy=call=0;
        }
    }
    void upd(int l0,int r0,int x){
        flush();
        if(l0<=l&&r<=r0){
            lazy=x;
            call=1;
            flush();
            return;
        }
        if(l>r0||r<l0) return;
        child[0].upd(l0,r0,x);
        child[1].upd(l0,r0,x);
        sum=child[0].sum+child[1].sum;
    }
    int qr(int l0,int r0){
        flush();
        if(l0<=l&&r<=r0) return sum;
        if(l>r0||r<l0) return 0;
        return child[0].qr(l0,r0)+child[1].qr(l0,r0);
    }
}t;


int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    t=segment(1,N);
    t.upd(3,7,5);
    cout<<t.qr(4,10)<<endl;

    return 0;
}
