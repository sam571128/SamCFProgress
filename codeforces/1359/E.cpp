#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll MOD = 998244353;
const ll N = 5e5+5;

ll fact[N];

void init(){
	fact[0] = 1;
	for(ll i = 1;i < N;i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}
}

ll fastpow(ll n, ll p){
	ll tmp = n, ans = 1;
	while(p){
		if(p&1){
			ans = (ans*tmp)%MOD;
		}
		tmp = (tmp*tmp)%MOD;
		p>>=1;
	}
	return ans;
}

ll inv(ll n){
	return fastpow(n, MOD-2);
}

ll divide(ll x, ll y){
	return (x*inv(y))%MOD;
}

ll nCr(ll n, ll r){
	if(r > n) return 0;
	return divide(fact[n],fact[n-r]*fact[r]%MOD);
}

int main(){
	fastio
	ll n,k,ans = 0;
	cin >> n >> k;
	init();
	for(ll i = 1;i <= n;i++){
		ll d = n/i;
		ans = (ans + nCr(d-1,k-1))%MOD;
	}
	cout << ans << "\n";
}