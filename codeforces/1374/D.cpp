#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	map<ll,ll> d;
	for(ll i = 0, tmp;i < n;i++){
		cin >> tmp;
		d[tmp%k]++;
	}
	if(d[0]==n){
		cout << 0 << "\n";
		return;
	}
	ll x = 0;
	for(auto itr = next(d.begin());itr!=d.end();itr++){
		ll r = itr->first;
		ll tmp = itr->second;
		x = max((k-r)+(tmp-1)*k,x);
	}
	cout << x + 1 << "\n";
	/*ll x = 0, tmp = 0, ans = 0;
	while(d[0]!=n){
		x++;
		x%=k;
		ans++;
		if(d[k-x]&&x!=0){
			d[k-x]--;
			d[0]++;
		}
	}
	cout << ans+1 << "\n";	*/
}

int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}