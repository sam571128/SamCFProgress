#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

signed main(){
	fastio
	int n,k,q;
	cin >> n >> k >> q;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int dp[k+1][n] = {}; //dp[j][i] => The number of paths when we walked j steps to i
	for(int i = 0;i < n;i++) dp[0][i] = 1;
	int sum[n] = {};
	for(int i = 0;i < k;i++){
		for(int j = 0;j < n;j++){
			if(j!=n-1) dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%MOD;
			if(j!=0) dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j])%MOD;
		}
	}
	for(int i = 0;i <= k;i++){
		for(int j = 0;j < n;j++){
			sum[j] = (sum[j]+dp[i][j]*dp[k-i][j])%MOD;
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		ans = (ans+arr[i]*sum[i]%MOD)%MOD;
	}	
	while(q--){
		int a,x;
		cin >> a >> x;
		a--;
		ans = (ans-arr[a]*sum[a]%MOD+x*sum[a]%MOD+MOD)%MOD;
		arr[a] = x;
		cout << ans << "\n";
	}
}