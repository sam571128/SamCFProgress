#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	int h[n];
	for(auto &x : h) cin >> x;
	int dp[n]; //dp[i] = The minimum cost when you stop at i-th stone
	dp[0] = 0; //Standing on the First stone do not cost anything
	for(int i = 1;i < n;i++){
		dp[i] = 1e18;
		for(int j = 1;j <= k;j++){
			if(i-j>=0) dp[i] = min(dp[i], dp[i-j] + abs(h[i]-h[i-j]));
		}
	}
	cout << dp[n-1] << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}