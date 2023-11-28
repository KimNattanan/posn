#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

int dp[5005][5005];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    string a,b; cin>>a>>b;
    int lena=a.length(),lenb=b.length();
    a=" "+a,b=" "+b;

    // Subsequence
    for(int i=1;i<=lena;++i){
        for(int j=1;j<=lenb;++j){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(a[i]==b[j]);
        }
    }

    // Substring
    for(int i=1;i<=lena;++i){
        for(int j=1;j<=lenb;++j){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
        }
    }


    return 0;
}
