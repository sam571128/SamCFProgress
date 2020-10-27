#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	int dp[2*n+1][n+1];
	memset(dp,0x3f3f3f,sizeof dp);
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr.begin() + 1, arr.end());
	dp[0][0] = 0;
	for(int i = 1; i <= n * 2; i++)
		for(int j = 0; j <= n; j++)
			dp[i][j] = min(dp[i - 1][j], j ? (dp[i - 1][j - 1]  + abs(arr[j] - i)) : (int)1e18);
	cout << dp[n * 2][n] << '\n';
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}