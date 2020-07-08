#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	unordered_map<ll,ll> m;
	bool ok = true;
	for(ll i = 0, tmp; i < n;i++){
		cin >> tmp;
		ll p = 0;
		while(tmp!=0){
			ll num = tmp%k;
			if(num > 1){
				ok = false;
				break;
			}
			if(m[p] && num){
				ok = false;
				break;
			}
			m[p] += num;
			tmp/=k;
			p++;
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}