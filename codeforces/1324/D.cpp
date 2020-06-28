#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n;
	cin >> n;
	ll a[n], b[n], diff[n];
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	for(ll i = 0;i < n;i++){
		diff[i] = a[i] - b[i];
	}
	ll ans = 0;
	sort(diff,diff+n);
	for(ll i = n-1;i > 0;i--){
		auto itr = upper_bound(diff,diff+i,-diff[i]);
		if(itr==diff+i) continue;
		else{
			ans += distance(itr, diff+i);
		}
	}
	cout << ans << "\n";
}