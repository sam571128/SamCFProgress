#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	string s;
	cin >> s;
	int n = s.size();
	int dp[n+1][2] = {}; 
	s = " " + s;
	for(int i = 1;i <= n;i++){
		if(s[i]=='0'){
			dp[i][0] = min(dp[i-1][0],dp[i-1][1]);
			dp[i][1] = min(dp[i-1][1],dp[i-1][0]+a)+b;
			if(i==1) dp[i][1] = a+b;
		}else{
			dp[i][1] = min(dp[i-1][1],dp[i-1][0]+a);
			dp[i][0] = 1e18;
			if(i==1) dp[i][1] = a;
		}
	}
	cout << min(dp[n][0],dp[n][1]) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}