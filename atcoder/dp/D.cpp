#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,cp;
	cin >> n >> cp;
	int w[n], v[n];
	for(int i = 0;i < n;i++) cin >> w[i] >> v[i];
	int dp[n][cp+1];
	memset(dp,0,sizeof dp);
	for(int i = w[0]; i <= cp; i++) dp[0][i] = v[0];
	for(int i = 1;i < n;i++){
		for(int j = 1;j <= cp;j++){
			dp[i][j] = max({dp[i][j],dp[i][j-1]});
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
			if(j >= w[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]] + v[i]);
		}
	}
	int ans = 0;
	for(int i = 0;i <= cp;i++) ans = max(ans,dp[n-1][i]);
	cout << ans << "\n";
}