#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll n,x;
	cin >> n >> x;
	vector<ll> v(n);
	for(auto &x : v) cin >> x;
	ll count = 0, ans = 0;
	sort(v.begin(),v.end());
	while(!v.empty()){
		count++;
		if(v.back()*count >= x){
			count  = 0;
			ans++;
		}
		v.pop_back();
	}
	cout << ans << "\n";
}

int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}