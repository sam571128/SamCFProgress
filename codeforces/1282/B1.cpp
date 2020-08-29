#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,p,k;
	cin >> n >> p >> k;
	int a[n+1];
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int dp[n+1];
	dp[0] = 0;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(i >= k){
			dp[i] = min(dp[i-1],dp[i-k]) + a[i];
		}else{
			dp[i] = dp[i-1] + a[i];
		}
		if(dp[i] <= p) ans = max(ans,i);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}