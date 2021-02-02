#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n], a[n], b[n];
	for(auto &x : arr) cin >> x;
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	for(int i = 1;i < n;i++){
		if(a[i] > b[i]){
			swap(a[i],b[i]);
		}
	}
	int dp[n][2] = {}; //end at this chain -> 0, continue -> 1
	dp[0][1] = abs(a[1]-b[1])+1;
	for(int i = 0;i < n-1;i++){
		if(a[i+1]!=b[i+1]){
			dp[i+1][0] = max({dp[i+1][0],dp[i][1]+arr[i+1], abs(b[i+1]-a[i+1])+1+arr[i+1]});
			if(i+1 != n-1) dp[i+1][1] = max({dp[i+1][1], dp[i][1] + a[i+2] - 0 + arr[i+1]+1 - b[i+2], abs(b[i+1]-a[i+1])+1+a[i+2] - 0 + arr[i+1]+1 - b[i+2]});
		}else{
			dp[i+1][0] = max(dp[i+1][0],1 + arr[i+1]);
			if(i+1 != n-1) dp[i+1][1] = max(dp[i+1][1], 1 + a[i+2] - 0 + arr[i+1] + 1 - b[i+2]);
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		//cout << dp[i][0] << " " << dp[i][1] << "\n";
		ans = max(dp[i][0],ans);
	}
	cout << ans << "\n";
}

signed main(){
	//fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}

/*
1
5
4 4 4 4 4 
-1 1 1 4 4 
-1 1 4 3 2
*/