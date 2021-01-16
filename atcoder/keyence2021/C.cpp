#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 998244353;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

signed main(){
	fastio
	int n,m,k;
	cin >> n >> m >> k;
	int grid[n][m] = {}, dp[n][m] = {};
	for(int i = 0;i < k;i++){
		int x,y;
		char c;
		cin >> x >> y >> c;
		x--,y--;
		if(c=='X') grid[x][y] = 1;
		if(c=='R') grid[x][y] = 2;
		if(c=='D') grid[x][y] = 3;
	}
	int tmp = 2*fastpow(3,MOD-2)%MOD;
	dp[0][0] = 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(j!=m-1&&(grid[i][j]==0||grid[i][j]==1||grid[i][j]==2)) dp[i][j+1] = (dp[i][j+1]+(grid[i][j] ? dp[i][j] : dp[i][j]*tmp))%MOD;
			if(i!=n-1&&(grid[i][j]==0||grid[i][j]==1||grid[i][j]==3)) dp[i+1][j] = (dp[i+1][j]+(grid[i][j] ? dp[i][j] : dp[i][j]*tmp))%MOD;
		}
	}
	cout << dp[n-1][m-1]*fastpow(3,n*m-k)%MOD << "\n";
}