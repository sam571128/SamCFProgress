#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

signed main(){
	fastio
	int n,k,d;
	cin >> n >> k >> d;
	int dp[n+1][n+1][2] = {};
	int ans = 0;
	dp[0][0][0] = 1;
	for(int i = 0;i <= n;i++){
		if(i!=n)
			for(int j = 0;j <= n;j++){
				for(int x = 1;x <= k;x++){
					if(x+j > n) continue;
					if(x >= d) dp[i+1][x+j][1] = (dp[i+1][x+j][1] + dp[i][j][0])%MOD;
					else dp[i+1][x+j][0] = (dp[i+1][x+j][0] + dp[i][j][0])%MOD;
					dp[i+1][x+j][1] = (dp[i+1][x+j][1] + dp[i][j][1])%MOD;
				}
			}
		ans = (ans + dp[i][n][1])%MOD;
	}
	cout << ans << "\n";
}