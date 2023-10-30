#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define ll long long

int a[100005];
int temp[100005];
int dp[100005];  // LIS[1..i]
int dp2[100005]; // LIS[1..i] including a[i]

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];


    // Increasing
    int cnt=0;
    for(int i=1;i<=n;++i){
        int idx=lower_bound(temp,temp+cnt,a[i])-temp;
        if(idx==cnt) ++cnt;
        temp[idx]=a[i];

        dp[i]=cnt;
        dp2[i]=idx+1;

    }


    // Non-Decreasing
    int cnt=0;
    for(int i=1;i<=n;++i){
        int idx=upper_bound(temp,temp+cnt,a[i])-temp;
        if(idx==cnt) ++cnt;
        temp[idx]=a[i];

        dp[i]=cnt;
        dp2[i]=idx+1;

    }


    return 0;
}
