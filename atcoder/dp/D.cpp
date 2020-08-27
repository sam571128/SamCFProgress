#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,cp;
	cin >> n >> cp;
	int w[n], v[n];
	for(int i = 0;i < n;i++) cin >> w[i] >> v[i];
	int dp[n][cp+1]; //The maximum value for the first n items and capacity
	for(int i = 0;i <= cp;i++) dp[0][i] = (i < w[0] ? 0: v[0]);
	for(int i = 1;i < n;i++){
		for(int	j = 0;j <= cp;j++){
			if(j==0) dp[i][j] = 0;
			else{
				dp[i][j] = dp[i][j-1];
				dp[i][j] = max(dp[i-1][j],dp[i][j]);
				if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
			}
		}
	}
	cout << dp[n-1][cp] << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}