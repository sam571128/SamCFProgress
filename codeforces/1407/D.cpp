//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int dp[n];
	memset(dp,0x3f3f3f,sizeof dp);
	dp[0] = 0;
	vector<int> ma = {0}, mi = {0};
	for(int i = 1;i < n;i++){
		dp[i] = dp[i-1]+1;
		int res = 1e18, ok = 1;
		while(!ma.empty()&&arr[ma.back()]<=arr[i]){
			if(arr[ma.back()] == arr[i]) ok = 0; 
			res = min(res,dp[ma.back()]+1);
			ma.pop_back();
		}
		if(!ma.empty()&&ok)
			res = min(res,dp[ma.back()]+1);
		ok = 1;
		while(!mi.empty()&&arr[mi.back()]>=arr[i]){
			if(arr[mi.back()] == arr[i]) ok = 0; 
			res = min(res,dp[mi.back()]+1);
			mi.pop_back();
		}
		if(!mi.empty()&&ok)
			dp[i] = min(dp[i],dp[mi.back()]+1);
		dp[i] = min(dp[i],res);
		ma.push_back(i);
		mi.push_back(i);
	}
	cout << dp[n-1] << "\n";
}