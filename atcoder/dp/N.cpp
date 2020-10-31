#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n], pref[n+1] = {};
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		pref[i+1] = pref[i] + arr[i]; 
	}
	int dp[n][n];
	memset(dp,0x3f3f3f,sizeof dp);
	for(int i = 0;i < n;i++) dp[i][i] = 0;
	for(int i = 0;i < n;i++){
		for(int j = i-1;~j;j--){
			for(int k = j;k <= i;k++){
				dp[j][i] = min(dp[j][i],dp[j][k]+dp[k+1][i]+pref[i+1]-pref[j]);
			}
		}
	}
	cout << dp[0][n-1] << "\n";
}