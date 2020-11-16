#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	int dp[n+1][m+1] = {};
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			dp[i][j] = max({dp[i-1][j]-1,dp[i][j-1]-1,dp[i][j]});
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+4-2);
			}
			ans = max(dp[i][j],ans);
		}
	}
	cout << ans << "\n";
}