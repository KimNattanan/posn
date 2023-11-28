#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll=long long;
using pii=pair<int,int>;
#define f first
#define s second

bool dp[5005][5005]; // s[i..j] is palindrome?

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    string s; cin>>s;
    int n=s.length();
    s=" "+s;
    
    // Substring
    for(int k=1;k<=n;++k){
        for(int i=1,j=k;j<=n;++i,++j){
            if(k==1) dp[i][j]=1;
            else if(k==2) dp[i][j]=(s[i]==s[j]);
            else if(s[i]==s[j]&&dp[i+1][j-1]) dp[i][j]=1;
        }
    }


    // Subsequence == LCS(s,s'), s'=reverse(s)


    return 0;
}
