#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 998244353;

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
	int n, m, k;
	cin >> n >> m >> k;
	int dp[k+1][k+1] = {};
	m = fastpow(m,MOD-2);
	dp[0][0] = 1;
	int ans = 0;
	for(int i = 0;i < k;i++){
		for(int j = 0;j <= i;j++){
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]*j%MOD)%MOD;
			dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] * (n-j)%MOD * m)%MOD;
		}
	}
	for(int i = 0;i <= k;i++){
		ans = (ans + dp[k][i])%MOD;
	}
	cout << ans << "\n";
}