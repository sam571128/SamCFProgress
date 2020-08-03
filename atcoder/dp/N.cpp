#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int a[n], b[n];
	for(auto &x : a) cin >> x;
	for(int i = 0;i < n;i++){
		b[i] = a[i];
		if(i!=0) b[i] += b[i-1];
	}
	int dp[n][n];
	memset(dp,0,sizeof dp);
	for(int i = 1;i < n;i++)
		for(int j = 0;j+i < n;j++){
			int l = j, r = j+i;
			dp[l][r] = 1e18;
			for(int k = l;k < r;k++){
				dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]+ b[r]-(l==0 ? 0 : b[l-1]));
			}
		}
	cout << dp[0][n-1] << "\n";
}