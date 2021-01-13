#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e3+5, MOD = 1e9+7;
int a[N][N], b[N][N], c[N][N], dp[N][N], grid[N][N];

//a[x][y] the way to get to (x,y) from left
//b[x][y] the way to get to (x,y) from top
//c[x][y] the way to get to (x,y) from top-left
//dp[i][j] all ways to get the (x,y)

signed main(){	
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			char c;
			cin >> c;
			if(c=='.') grid[i][j] = 0;
			else grid[i][j] = 1;
		}
	}
	dp[1][1] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(grid[i][j]) continue;
			a[i][j] = (a[i][j]+a[i][j-1]+dp[i][j-1])%MOD;
			b[i][j] = (b[i][j]+b[i-1][j]+dp[i-1][j])%MOD;
			c[i][j] = (c[i][j]+c[i-1][j-1]+dp[i-1][j-1])%MOD;
			dp[i][j] = (dp[i][j]+a[i][j]+b[i][j]+c[i][j])%MOD;
		}
	}
	cout << dp[n][m] << "\n";
}