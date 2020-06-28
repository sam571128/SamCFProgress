#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	ll arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n,greater<ll>());
	ll ans = 0;
	bool ok = true;
	for(ll i = 0, sum = 0;i < n;i++){
		sum += arr[i], ans++;
		if(sum/(i+1)<k){
			ok = false;
			break;
		}
	}
	cout << ans-(ok ? 0 : 1) << "\n";
}

int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}