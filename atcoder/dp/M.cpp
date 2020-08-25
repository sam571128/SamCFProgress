#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;
signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int a[n];
	for(auto &x : a) cin >> x;
	int dp[n][k+1]; //nth child, the total sum of candies => how many ways
	memset(dp,0,sizeof dp);
	for(int j = 0;j <= k;j++){
		if(j > a[0]) dp[0][j] = 0;
		else{
			dp[0][j] = 1;
		}
	}
	for(int i = 1;i < n;i++){
		vector<int> pref(k+2,0);
		for(int j = 0;j <= k;j++){
			pref[j+1] = (pref[j+1] + dp[i-1][j])%MOD;
			pref[j+1] = (pref[j+1] + pref[j])%MOD;	
		}
		for(int j = 0;j <= k;j++){
			//cout << j << " " << j+1 << " " << max((int)0,j-a[i]) << ' ' << pref[j+1] << " " << pref[max((int)0,j-a[i])] << "\n";
			dp[i][j] = (dp[i][j] + pref[j+1] - pref[max((int)0,j-a[i])]+MOD)%MOD;
		}
		/*for(int x = max((int)0,j-a[i]); x <= j; x++){
				dp[i][j] = (dp[i][j] + dp[i-1][x])%MOD;
		}*/
	}
	cout << dp[n-1][k] << "\n";
}