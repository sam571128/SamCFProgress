#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int a[n];
	vector<int> pref(n+1,0);
	for(int i = 0;i < n;i++){
		cin >> a[i];
		pref[i+1] += a[i] + pref[i];
	}
	int dp[n][n];
	memset(dp,0,sizeof dp);
	for(int i = n-1;i >= 0;i--){
		for(int j = i+1;j < n;j++){
			if(i==j) dp[i][j] = a[i];
			else{
				dp[i][j] = 1e18;
				for(int k = i;k <= j;k++){
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + pref[j+1]-pref[i]);
				}
			}
		}
	}
	cout << dp[0][n-1] << "\n";
}