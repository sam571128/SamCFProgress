#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int dp[n] = {};
	int arr[n];
	int ans = 0;
	for(auto &x : arr) cin >> x;
	for(int i = 0;i < n;i++){
		if(i+arr[i] < n){
			dp[i+arr[i]] = max(dp[i+arr[i]],dp[i] + arr[i]);
		}
		else ans = max(ans,dp[i]+arr[i]);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}