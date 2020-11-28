#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k,p;
	cin >> n >> k >> p;
	int pref[n+1] = {};
	for(int i = 1;i <= n;i++){
		cin >> pref[i];
		pref[i] = (pref[i]+pref[i-1])%p;
	}
	int dp[p+1][k+1];
	memset(dp,-0x3f3f3f,sizeof dp);
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = k;j;j--){
			for(int t = 0; t < p;t++){
				dp[pref[i]][j] = max(dp[pref[i]][j],dp[t][j-1]+(pref[i]-t+p)%p);
			}
		}
	}
	cout << dp[pref[n]][k] << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}