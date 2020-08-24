//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	//fastio
	string s,t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int dp[n+1][m+1];
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			if(i==0||j==0) dp[i][j] = 0;
			else if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	//cout << dp[n][m] << "\n";
	string ans;
	for(int i = 0;i < dp[n][m];i++) ans += 'a';
	int i = n, j = m, ind = dp[n][m];
	while(i > 0&&j > 0){
		if(s[i-1]==t[j-1]){
			ans[ind-1] = s[i-1];
			i--,j--,ind--;
		}else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}else{
			j--;
		}
	}
	cout << ans << "\n";
}