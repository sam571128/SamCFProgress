#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int h[n];
	for(auto &x : h) cin >> x;
	int dp[n];
	memset(dp,0x3f3f3f,sizeof dp);
	dp[0] = 0;
	for(int i = 0;i < n;i++){
		if(i-1 >= 0) dp[i] = min(dp[i],dp[i-1]+abs(h[i]-h[i-1]));
		if(i-2 >= 0) dp[i] = min(dp[i],dp[i-2]+abs(h[i]-h[i-2]));
	}
	cout << dp[n-1] << "\n";
}