#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int a[n],b[n],c[n];
	for(int i = 0;i < n;i++) cin >> a[i] >> b[i] >> c[i];
	int dp[n][3];
	dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];
	for(int i = 1;i < n;i++){
		dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a[i];
		dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + b[i];
		dp[i][2] = max(dp[i-1][1],dp[i-1][0]) + c[i];
	}
	cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << "\n";
}