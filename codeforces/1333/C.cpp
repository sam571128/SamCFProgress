#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	ll arr[n+1];
	map<ll,ll> dp;
	dp[0] = 0;
	for(ll i = 1;i<=n;i++) cin >> arr[i];
	ll ans = 0, tmp = 0;
	for(ll i = 1, sum = 0;i <= n;i++){
		sum += arr[i];
		if(dp.count(sum)) tmp = max(tmp,dp[sum]+1);
		ans += (i-tmp);
		dp[sum] = i; 
	}
	cout << ans << "\n";
}