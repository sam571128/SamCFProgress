#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define map gp_hash_table

using namespace std;
using namespace __gnu_pbds;

const int MOD = 1e9+7;

int inv[25];

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res*n%MOD;
		n = n*n%MOD;
		p >>= 1;
	}
	return res;
}

int nCr(int n, int r){
	if(r > n) return 0;
	if(r > n-r) r = n-r;
	int res = 1;
	for(int i = 1;i <= r;i++){
		res = res * ((n-i+1) % MOD)%MOD * inv[i] % MOD;
	}
	return res;
}

void init(){
	for(int i = 1;i <= 24;i++){
		inv[i] = fastpow(i,MOD-2);
	}
}

signed main(){
	fastio
	init();
	int n,s;
	cin >> n >> s;
	vector<int> v(n);
	for(auto &x : v) cin >> x;
	int ans = 0;
	for(int i = 0;i < (1<<n);i++){
		int now = 1, tt = s;
		for(int j = 0;j < n;j++){
			if(i&(1<<j)) tt -= (v[j]+1), now *= -1;
		}
		if(tt < 0) continue;
		ans = (ans + now * nCr(n-1+tt,n-1)%MOD + MOD)%MOD;
	}
	cout << ans << "\n";
}