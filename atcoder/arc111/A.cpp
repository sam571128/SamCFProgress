#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int MOD = 1e9+7;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	MOD = m*m;
	cout << fastpow(10,n)/m << "\n";
}