#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e3+5, MOD = 998244353;
int dp[N][N];

signed main(){
	fastio
	int a,b,c;
	cin >> a >> b >> c;
	for(int i = 0;i < N;i++) dp[i][0] = 1, dp[0][i] = 1;
	for(int i = 1;i < N;i++){
		for(int j = 1;j < N;j++){
			dp[i][j] = (dp[i-1][j]+dp[i-1][j-1]*j%MOD)%MOD;
		}
	}
	cout << dp[a][b]*dp[b][c]%MOD*dp[c][a]%MOD << "\n";
}