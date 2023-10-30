#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define ll long long

int a[5005];
int dp[5005];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];


    // Increasing
    for(int i=1;i<=n;++i){
        dp[i]=1;
        for(int j=1;j<i;++j){
            if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
        }
    }


    // Non-Decreasing
    for(int i=1;i<=n;++i){
        dp[i]=1;
        for(int j=1;j<i;++j){
            if(a[j]<=a[i]) dp[i]=max(dp[i],dp[j]+1);
        }
    }


    return 0;
}
