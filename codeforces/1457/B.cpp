#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	int ans = 1e18;
	for(auto &x : arr) cin >> x;
	for(int c = 1;c <= 100;c++){
		deque<int> v;
		int dp[n];
		memset(dp,0x3f3f3f,sizeof dp);
		dp[0] = (arr[0]!=c);
		for(int i = 1;i < n;i++){
			if(arr[i]==c) dp[i]=dp[i-1];
			dp[i] = min(dp[i],(i-k >= 0 ? dp[i-k] : 0)+1);
		}
		ans = min(dp[n-1],ans);
	}		
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}