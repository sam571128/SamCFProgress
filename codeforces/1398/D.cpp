#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 205;
int dp[N][N][N];
signed main(){
	fastio
	int r,g,b;
	cin >> r >> g >> b;
	int x[r], y[g], z[b];
	for(auto &t : x) cin >> t; for(auto &t : y) cin >> t; for(auto &t : z) cin >> t;
	sort(x,x+r);
	sort(y,y+g);
	sort(z,z+b);
	
	int ans = 0;
	for(int i = 0;i <= r;i++){
		for(int j = 0;j <= g;j++){
			for(int k = 0;k <= b;k++){
				if(i&&j) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k] + x[i-1]*y[j-1]);
				if(j&&k) dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k-1] + y[j-1]*z[k-1]);
				if(i&&k) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1] + x[i-1]*z[k-1]);
				ans = max(ans,dp[i][j][k]);
			}
		}
	}
	cout << ans << "\n";
	
}