#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int grid[3][N], dp[N][4];

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < 3;i++){
		for(int j = 1;j <= n;j++){
			cin >> grid[i][j];
		}
	}
	fill(&dp[0][0],&dp[n][3],-1e18);
	dp[0][0] = 0;
	auto sum = [&](int j, int l, int r){
		int res = 0;
		if(l > r) swap(l,r);
		for(int i = l;i <= r;i++){
			res += grid[i][j];
		}
		return res;
	};
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 3;j++){
			for(int k = 0;k < 3;k++){
				dp[i][j] = max(dp[i][j],dp[i-1][k] + sum(i,j,k));
			}
		}
		dp[i][0] = max(dp[i][0], dp[i-1][3] + sum(i,0,2)); 
		dp[i][2] = max(dp[i][2], dp[i-1][3] + sum(i,0,2));
		dp[i][3] = max(dp[i][3], max(dp[i-1][0],dp[i-1][2]) + sum(i,0,2));
	}
	cout << dp[n][2] << "\n";
}