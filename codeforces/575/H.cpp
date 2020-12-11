#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e6+10, MOD = 1e9+7;
int fact[N];

void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++)
		fact[i] = fact[i-1]*i%MOD;
}

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res * n % MOD;
		n = n*n%MOD;
		p>>=1;
	}
	return res;
}

signed main(){
	fastio
	init();
	int n;
	cin >> n;
	cout << (fact[2*n+2]*fastpow(fact[n+1],MOD-2)%MOD*fastpow(fact[n+1],MOD-2)%MOD-1+MOD)%MOD << "\n";
}