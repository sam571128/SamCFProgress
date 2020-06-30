#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9;
int main(){
	fastio
	ll n;
	cin >> n;
	ll arr[n];
	for(auto &x : arr) cin >> x;
	ll ans = 0;
	for(ll ma = 0;ma < 31;ma++){
		ll sum = 0;
		ll tmp = 0;
		for(ll i = 0;i < n;i++){
			ll val = (arr[i] > ma ? -INF : arr[i]);
			sum = max((ll)0,sum+val);
			tmp = max(sum,tmp);
			ans = max(tmp-ma,ans);
		}
	}
	cout << ans << "\n";
}