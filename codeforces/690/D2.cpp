#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll MOD = 1e6+3;

ll fact[MOD];

ll fastpow(ll n,ll p){
	ll ans = 1;
	while(p){
		if(p&1){
			ans = (ans*n)%MOD;
		}
		n = (n*n)%MOD;
		p>>=1;
	}
	return ans;
}

void init(){
	fact[0] = 1;
	for(int i = 1;i < MOD;i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}
}

int main(){
	fastio
	init();
	ll n,c;
	cin >> n >> c;
	//cout << fact[n+c] << " " << fastpow(fact[n],MOD-2) << " " << fastpow(fact[c],MOD-2) << "\n";
	cout << (fact[n+c]*fastpow(fact[n],MOD-2)*fastpow(fact[c],MOD-2))%MOD-1;
}