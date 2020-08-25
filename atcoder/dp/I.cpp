//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	double p[n];
	for(auto &x : p) cin >> x;
	double dp[n][n+1]; //Ends with which, how many heads
	memset(dp,0,sizeof dp);
	dp[0][0] = 1-p[0], dp[0][1] = p[0];
	for(int i = 1;i < n;i++){
		for(int j = 0;j <= i+1;j++){
			dp[i][j] += dp[i-1][j] * (1-p[i]);
			dp[i][j] += dp[i-1][j-1] * p[i];
		}
	}
	double ans = 0;
	for(int i = n/2+n%2; i <= n;i++){
		ans += dp[n-1][i];
	}
	cout << fixed << setprecision(10) << ans << "\n";
}