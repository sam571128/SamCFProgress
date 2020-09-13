#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;
const int N = 1e6+5;

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
	int n;
	cin >> n;
	cout << (((fastpow(10,n)+fastpow(8,n)+MOD)%MOD-fastpow(9,n)+MOD)%MOD-fastpow(9,n)+MOD)%MOD << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}