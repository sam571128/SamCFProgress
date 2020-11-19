#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int dp[n+2][2] = {};
	int ans = 0;
	for(int i = 2;i < n+2;i++){
		dp[i][0] = (i>2&&arr[i-2] > arr[i-3] ? dp[i-1][0] + 1 : 1);
		dp[i][1] = max((i>2&&arr[i-2] > arr[i-3] ? dp[i-1][1] + 1 : 1),(i>3&&arr[i-2] > arr[i-4] ? dp[i-2][0] + 1 : 1));
		ans = max({ans,dp[i][0],dp[i][1]});
	}
	cout << ans << "\n";
}