#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

signed main(){
	fastio
	int n;
	cin >> n;
	string s;
	cin >> s;
	int dp[n][3] = {}, cnt = 1;
	for(int i = 0;i < n;i++){
		if(s[i]=='a'){
			dp[i][0] = (dp[i][0] + cnt)%MOD;
		}else if(s[i]=='b'){
			if(i>0)
				dp[i][1] = (dp[i][1] + dp[i-1][0])%MOD;
		}else if(s[i]=='c'){
			if(i>0)
				dp[i][2] = (dp[i][2] + dp[i-1][1])%MOD;
		}else{
			dp[i][0] = (dp[i][0]*3 + cnt)%MOD;
			if(i>0)
				dp[i][1] = (dp[i][1]*3 + dp[i-1][0])%MOD;
			if(i>0)
				dp[i][2] = (dp[i][2]*3 + dp[i-1][1])%MOD;
			cnt = cnt*3%MOD;
		}
		if(i!=n-1){
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = dp[i][1];
			dp[i+1][2] = dp[i][2];
		}
	}
	cout << dp[n-1][2] << "\n";
}