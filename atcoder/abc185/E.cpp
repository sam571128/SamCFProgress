#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	//Edit Distance
	int n,m;
	cin >> n >> m;
	int a[n], b[m];
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	int dp[n+1][m+1] = {};
	memset(dp,0x3f3f3f,sizeof dp);
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			if(i==0) dp[i][j] = j;
			else if(j==0) dp[i][j] = i;
			else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
		}
	}
	cout << dp[n][m] << "\n";
}