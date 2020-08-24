//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5, INF = 1e18;

signed main(){
	fastio
	int n,cp;
	cin >> n >> cp;
	int w[n], v[n];
	for(int i = 0;i < n;i++) cin >> w[i] >> v[i];
	int dp[n][N];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < N;j++){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0, dp[0][v[0]] = w[0];
	for(int i = 1;i < n;i++){
		for(int j = 0;j < N;j++){
			dp[i][j] = min(dp[i-1][j], dp[i][j]);
			if(j >= v[i]){
				dp[i][j] = min(dp[i][j],dp[i-1][j-v[i]] + w[i]);
			}
		}
	}
	int ans = 0;
	for(int j = 0;j < N;j++){
		if(dp[n-1][j] <= cp) ans = j; 
	}
	cout << ans << "\n";
}