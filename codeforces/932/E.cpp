#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p%2) res = res*n%MOD;
		n = n*n %MOD;
		p/=2;
	}
	return res;
}

signed main(){
	fastio
	int n, k;
	cin >> n >> k;
	int dp[k+1][k+1] = {};
	dp[1][1] = n;
	int ans = 0;
	for(int i = 1;i < k;i++){
		for(int j = 1;j <= i;j++){
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]*j%MOD)%MOD;
			dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] * (n-j))%MOD;
		}
	}
	for(int i = 1;i <= k;i++){
		//cout << fastpow(2,n-i) << "\n";
		ans = (ans + fastpow(2,n-i)*dp[k][i]%MOD)%MOD;
	}
	cout << ans << "\n";
}