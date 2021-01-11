#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 998244353;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res * n %MOD;
		n = n*n%MOD;
		p>>=1;
	}
	return res;
}

signed main(){
	fastio
	int a,b,c;
	cin >> a >> b >> c;
	cout << a*(a+1)%MOD*fastpow(2,MOD-2)%MOD*b%MOD*(b+1)%MOD*fastpow(2,MOD-2)%MOD*c%MOD*(c+1)%MOD*fastpow(2,MOD-2)%MOD;
}