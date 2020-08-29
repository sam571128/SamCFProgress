#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

void solve(){
	int sum = 0;
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	for(auto x : a) sum = (sum + x)%MOD;
	int ans = 0;
	for(auto x : a){
		ans = (ans + (sum-x)*x%MOD+MOD)%MOD;
	}
	cout << ans*fastpow(2,MOD-2)%MOD << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}