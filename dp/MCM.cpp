#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define ll long long

const ll inf=1e18+7;

// https://beta.programming.in.th/tasks/codecube_025

ll a[605],sum[605][605],dp[605][605];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        sum[i][i]=a[i];
        for(int j=i+1;j<=n;++j) sum[i][j]=sum[i][j-1]+a[j];
    }
    for(int k=1;k<=n;++k){
        for(int i=1,j=k;j<=n;++i,++j){
            if(k==1) dp[i][j]=0;
            else{
                dp[i][j]=0;
                for(int mid=i;mid<j;++mid){
                    dp[i][j]=max(dp[i][j],dp[i][mid]+dp[mid+1][j]
                                          +sum[i][mid]+sum[mid+1][j]+min(sum[i][mid],sum[mid+1][j]));
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;

    return 0;
}
