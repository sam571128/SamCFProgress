#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	int maxn = (1<<22)-1;
	vector<int> dp(1<<22,-1);
	for(int i = 0, tmp;i < n;i++){
		cin >> arr[i];
		dp[arr[i]] = arr[i];
	}
	for(int i = 0;i < 22;i++){
		for(int mask = 0; mask <= maxn; mask++){
			if(~dp[mask]) continue;
			if((mask&(1<<i))&&~dp[mask^(1<<i)]) dp[mask] = dp[mask^(1<<i)];
		}
	}
	for(int i = 0;i < n;i++){
		cout << dp[maxn^arr[i]] << " ";
	}

}