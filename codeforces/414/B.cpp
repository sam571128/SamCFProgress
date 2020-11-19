#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int dp[k][n+1] = {};
	fill(dp[0], dp[0]+n+1, 1);
	for(int i = 0;i < k-1;i++){
		for(int j = 1;j <= n;j++){
			for(int k = j; k <= n;k += j){
				dp[i+1][k] = (dp[i+1][k] + dp[i][j])%MOD;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) ans = (ans + dp[k-1][i])%MOD;
	cout << ans << "\n";
}