#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll ans = 0;
	ll mi = 1e18;
	vector<array<ll,2>> v(n);
	for(ll i = 0, a, b;i < n;i++){
		cin >> v[i][0] >> v[i][1];
	}
	for(ll i = 0;i < n;i++){
		ll ni = (i+1)%n;
		ll val = min(v[ni][0],v[i][1]);
		ans += v[ni][0] - val;
		mi = min(val, mi);
	}
	ans += mi;
	cout << ans << "\n";
}

int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}