#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll n;
	cin >> n;
	array<ll,2> arr[n];
	for(ll i = 0;i < n;i++) cin >> arr[i][0] >> arr[i][1];
	ll ans = 0, mi = 1e18;
	for(ll i = 0;i < n;i++){
		mi = min({arr[i][1],arr[(i+1)%n][0], mi});
		arr[(i+1)%n][0] = max((ll)0,arr[(i+1)%n][0]-arr[i][1]);
		ans += arr[(i+1)%n][0];
	}
	cout << ans + mi << "\n";
}

int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}