#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,q;
	cin >> n >> q;
	int arr[n+1];
	for(int i = 1;i <= n;i++) cin >> arr[i];
	int dp[n+1][4]; //0->plus, 1->minus, 2-> don't choose (plus), 3-> don't choose(minus);
	memset(dp,0,sizeof dp);
	dp[1][0] = arr[1];
	for(int i = 2;i <= n;i++){
		dp[i][0] = max({dp[i][0],dp[i-1][1]+arr[i],dp[i-1][3]+arr[i]});
		dp[i][1] = max({dp[i][1],dp[i-1][0]-arr[i],dp[i-1][2]-arr[i]});
		dp[i][2] = max({dp[i][2],dp[i-1][0],dp[i-1][2]});
		dp[i][3] = max({dp[i][3],dp[i-1][1],dp[i-1][3]});
	}
	cout << max({dp[n][0],dp[n][1],dp[n][2],dp[n][3]}) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}