#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int dp[n+1][2] = {};
	dp[0][0] = 1, dp[0][1] = 1;
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		if(s[0]=='A'){
			dp[i][0] = 2*dp[i-1][0]+dp[i-1][1];
			dp[i][1] = dp[i-1][1];
		}else{
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][0]+2*dp[i-1][1];
		}
	}
	cout << dp[n][1] << "\n";
}