#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n],b[n];
	for(int i = 0;i < n;i++) cin >> a[i] >> b[i];
	int dp[n][10];
	for(int i = 0; i < 10;i++) dp[0][i] = i*b[0];
	for(int i = 1;i < n;i++){
		for(int j = 0;j < 10;j++){
			dp[i][j] = 1e18;
			for(int k = 0;k < 10;k++){
				if(a[i-1]+k!=a[i]+j) dp[i][j] = min(dp[i][j],j*b[i]+dp[i-1][k]); 
			}
		}
	}
	int ans = 1e18;
	for(int i = 0;i < 10;i++) ans = min(dp[n-1][i],ans);
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}