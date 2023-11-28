#include<bits/stdc++.h>
using namespace std;

int dp[5005][5005];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    string a,b; cin>>a>>b;
    int lena=a.size(),lenb=b.size();
    a=" "+a;
    b=" "+b;
    for(int i=1;i<=lena;++i) dp[i][0]=i;
    for(int j=1;j<=lenb;++j) dp[0][j]=j;
    for(int i=1;i<=lena;++i){
        for(int j=1;j<=lenb;++j){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j],  // delete
                               dp[i][j-1],  // insert
                               dp[i-1][j-1] // change
                             })+1;
	    }
	}
	cout<<dp[lena][lenb];

	return 0;
}