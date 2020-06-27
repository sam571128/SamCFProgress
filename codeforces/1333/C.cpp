#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


int main(){
	fastio
	ll n;
	cin >> n;
	map<ll,ll> dp;
	ll sum = 0, last = 0, ans = 0;
	dp[0] = 0;
	for(int i = 1, tmp;i <= n;i++){
		cin >> tmp;
		sum += tmp;
		if(dp.count(sum)) last = max(last, dp[sum]+1);
		dp[sum] = i;
		ans += i-last;
	}
	cout << ans << "\n";
}