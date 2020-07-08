#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll MOD = 998244353;
const int N = 2e5+5;
ll fact[N];

void init(){
	fact[0] = fact[1] = 1;
	for(int i = 2;i < N;i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}
}

ll fastpow(ll n, ll p){
	ll res = 1;
	while(p){
		if(p&1) res = (res*n)%MOD;
		n = n*n%MOD;
		p>>=1; 
	}
	return res;
}

signed main(){
	fastio
	init();
	ll n,m;
	cin >> n >> m;
	if(n <= 2){
		cout << 0 << "\n";
		return 0;
	}
	ll res = fact[m] * fastpow(fact[n-1],MOD-2) %MOD * fastpow(fact[m-n+1],MOD-2)%MOD;
	res = res * fastpow(2,n-3)%MOD * (n-2)%MOD;
	cout << res << "\n";
}