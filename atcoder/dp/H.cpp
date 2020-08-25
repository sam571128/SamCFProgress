//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e3+5;
const int MOD = 1e9+7;
int grid[N][N];

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++){
		char tmp;
		cin >> tmp;
		if(tmp=='#') grid[i][j] = 1;
	}
	int dp[n][m];
	memset(dp,0,sizeof dp);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(grid[i][j]) dp[i][j] = 0;
			else if(i==0&&j==0) dp[i][j] = 1;
			else if(i==0) dp[i][j] = dp[i][j-1];
			else if(j==0) dp[i][j] = dp[i-1][j];
			else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
		}
	}
	cout << dp[n-1][m-1] << "\n";
}