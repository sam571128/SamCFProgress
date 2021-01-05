#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int dp[n] = {};
	int arr[n];
	for(auto &x : arr) cin >> x;
	int now = 0;
	for(int i = n-1;~i;i--){
		now = max(now-1,arr[i]+1);
		dp[i] = max(dp[i],now);
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		ans += (dp[i] = max(dp[i],(i==0 ? 0 : dp[i-1])))-arr[i]-1;
	}
	cout << ans << "\n";
}