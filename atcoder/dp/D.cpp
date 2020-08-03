#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dp[105][(int)1e5+5];

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int w[n+1], v[n+1];
	for(int i = 1;i <= n;i++) cin >> w[i] >> v[i];
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= m;j++){
			if(j-w[i] >= 0) dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n][m] << "\n";
}