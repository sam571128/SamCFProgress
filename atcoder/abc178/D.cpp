#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;
const int N = 2005;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

int fact[N];

void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++){
		fact[i] = fact[i-1] * i % MOD;
	}
}

void solve(){
	init();
	int n;
	cin >> n;
	int ans = 0, i = 1;
	while(n-3*i >= 0){
		//cout << n-3*i << " " << i-1 << "\n";
		//cout << fact[n-3*i+i-1]*fastpow(fact[n-3*i],MOD-2)%MOD*fastpow(fact[i-1],MOD-2)%MOD << "\n";
		ans = (ans + fact[n-3*i+i-1]*fastpow(fact[n-3*i],MOD-2)%MOD*fastpow(fact[i-1],MOD-2)%MOD)%MOD;
		i++;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}