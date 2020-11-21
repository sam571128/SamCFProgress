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
	dp[0] = 0;
	for(int i = 1;i < n;i++){
		dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]),(i >= 2 ? dp[i-2] + abs(arr[i]-arr[i-2]) : INT_MAX));
	}
	cout << dp[n-1] << "\n";
}