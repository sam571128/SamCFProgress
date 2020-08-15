#include <bits/stdc++.h>
 
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
signed main(){
	fastio
		int n, k;
	cin >> n >> k;
	vector<int> c(n+1), p(n+1);
	vector<vector<int>> dp(n+1, vector<int>(1)), mx = dp;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 1; i <= n; i++) {
		int it = i;
		mx[i][0] = -1e18;
		it = p[it];
		while(true) {
			dp[i].push_back(dp[i].back()+c[it]); 
			mx[i].push_back(max(mx[i].back(), dp[i].back()));
			if(it == i)
				break;
			it = p[it];
		}
	}
	int ans = -1e18;
	for(int i = 1; i <= n; i++) {
		int x = dp[i].size()-1;
		int w = k/x, res = k%x;
		int cur = -1e18;
		if(dp[i][x] > 0) {
			cur = dp[i][x]*w+max<int>(0, mx[i][res]);
		}
		if(w) {
			cur = max(cur, dp[i][x]*(w-1) + mx[i][x]);
		}
		cur = max(cur, mx[i][min(x, k)]);
		ans = max(ans, cur);
	}
	cout << ans << '\n';
 
	return 0;
}