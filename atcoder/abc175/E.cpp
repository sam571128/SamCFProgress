#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e3+5;
int grid[N][N];
int dp[N][N][4];
signed main(){
	fastio
	int r,c,k;
	cin >> r >> c >> k;
	while(k--){
		int x,y,v;
		cin >> x >> y >> v;
		grid[x][y] = v;
	}
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			for(int k = 0;k < 4;k++){
				if(i) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
				if(j) dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]);
				if(k){
					dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + grid[i][j]);
					for(int l = 0;l < 4;l++){
						dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][l] + grid[i][j]);
					}
				}
			}
		}
	}
	/*for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			cout << i << " " << j << "\n";
			for(int k = 0;k < 4;k++){
				cout << dp[i][j][k] << " ";
			}
			cout << "\n";
		}
	}*/
	cout << max({dp[r][c][0],dp[r][c][1],dp[r][c][2],dp[r][c][3]});
}