#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 105;
int dp[2][N][N*N];

void solve(){
	int n;
	cin >> n;
	fill(&dp[0][0][0],&dp[1][N-1][N*N-1],-1e9);
	dp[0][0][0] = 0;
	int a[n+1], b[n+1];
	int sum = 0;
	for(int i = 1;i <= n;i++) cin >> a[i] >> b[i], sum += b[i];
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= i;j++){
			for(int k = 0;k < N*N;k++){
				dp[i&1][j][k] = dp[(i+1)&1][j][k];
				if(k>=a[i]&&j){
					dp[i&1][j][k] = max(dp[i&1][j][k],dp[(i+1)&1][j-1][k-a[i]] + b[i]);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		double ans = 0;
		for(int k = 0;k < N*N;k++){
			ans = max(ans,min((double)k,((double)dp[n&1][i][k]+(double)sum)/2));
		}
		cout << ans << " ";
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}