#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,h,l,r;
	cin >> n >> h >> l >> r;
	int a[n+1];
	for(int i = 1;i <= n;i++) cin >> a[i];
	int dp[n+1][h];
	memset(dp,-0x3f, sizeof dp);
	dp[0][0] = 0;	
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < h;j++){
			dp[i][j] = max(dp[i-1][(j-a[i]+h)%h],dp[i-1][(j-a[i]+1+h)%h])+(l <= j&& r >= j);
		}
	}
	int ans = 0;
	for(int i = 0;i < h;i++){
		ans = max(dp[n][i],ans);
	}
	cout << ans << "\n";
}