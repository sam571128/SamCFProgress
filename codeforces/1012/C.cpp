#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e3+5;
int dp[N][N][2]; //dp[i][j][k] means when idx = 1, we will have built j houses, and k represents if we should build on i

signed main(){
	fastio
	int n;
	cin >> n;
	int h[n+1] = {};
	h[0] = 1e18;
	for(int i = 1;i <= n;i++) cin >> h[i];
	memset(dp,0x3f3f3f,sizeof dp);
	dp[0][0][0] = dp[1][1][1] = dp[1][0][0] = 0;
	for(int i = 2;i <= n;i++){
		dp[i][0][0] = 0;
		for(int j = 1;j <= (n+1)/2;j++){
			dp[i][j][0] = min(dp[i-1][j][1] + max((int)0,h[i]-h[i-1]+1), dp[i-1][j][0]);
			dp[i][j][1] = min(dp[i-2][j-1][0] + max((int)0,h[i-1]-h[i]+1), dp[i-2][j-1][1]+max((int)0,h[i-1]-min(h[i-2],h[i])+1));
			//cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
		}
	}
	for(int i = 1;i <= (n+1)/2;i++){
		cout << min(dp[n][i][0],dp[n][i][1]) << " ";
	}
}