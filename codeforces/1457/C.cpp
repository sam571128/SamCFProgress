#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,p,k;
	cin >> n >> p >> k;
	p--;
	int dp[n] = {};
	string s;
	cin >> s;
	int x,y;
	cin >> x >> y;
	for(int i = 0;i < n;i++){
		if(s[i]!='1') dp[i] += x;
		if(i-k >= 0) dp[i] += dp[i-k];
	}
	int ans = 1e18;
	for(int i = p;i < n;i++){
		ans = min(dp[i+(n-1-i)/k*k]-(i-k>=0 ? dp[i-k] : 0)+(i-p)*y,ans);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}