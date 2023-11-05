#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;

const int N=1e5;

int arr[N+5];

struct segment{
    vector<segment> child;
    int l,r,mid;
    int sum;
    segment(int l_=0,int r_=0){
        l=l_,r=r_,mid=l+(r-l>>1);
        sum=0;
    }
    void build(){
        if(l==r) return void(sum=arr[l]);
        child.emplace_back(l,mid);
        child.emplace_back(mid+1,r);
        child[0].build(),child[1].build();
        sum=child[0].sum+child[1].sum;
    }
    int qr(int l0,int r0){
        if(l0<=l&&r<=r0) return sum;
        if(l>r0||r<l0) return 0;
        return child[0].qr(l0,r0)+child[1].qr(l0,r0);
    }
}t;


int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    t=segment(1,N);
    t.build();
    cout<<t.qr(4,10)<<endl;

    return 0;
}
