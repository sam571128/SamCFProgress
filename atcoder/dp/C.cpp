#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n][3];
	for(int i = 0;i < n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	int dp[n][3]; //dp[i][j] = The maximum point we can get on i-th day doing the j-th activity
	dp[0][0] = a[0][0], dp[0][1] = a[0][1], dp[0][2] = a[0][2];
	for(int i = 1;i < n;i++){
		for(int j = 0;j < 3;j++){
			dp[i][j] = 0;
			for(int k = 0;k < 3;k++){
				if(j!=k) dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);
			}
		}
	}
	cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}