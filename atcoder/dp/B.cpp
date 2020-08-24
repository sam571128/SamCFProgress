#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int h[n];
	for(auto &x : h) cin >> x;
	int dp[n];
	memset(dp,0x3f3f3f,sizeof dp);
	dp[0] = 0;
	for(int i = 0;i < n;i++){
		for(int j = max((int)0,i-k);j < i;j++){
			dp[i] = min(dp[i],dp[j] + abs(h[i]-h[j]));
		}
	}
	cout << dp[n-1] << "\n";
}