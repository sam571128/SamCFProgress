#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

int fac[(int)1e6+5];

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1){
			res = (res*n)%MOD;
		}
		n = (n*n)%MOD;
		p>>=1;
	}
	return res;
}

void init(){
	fac[0] = 1;
	for(int i = 1;i < (int)1e6+5;i++){
		fac[i] = (fac[i-1] * i)%MOD;
	}
}

signed main(){
	fastio
	init();
	int n;
	cin >> n;
	cout << (fac[n]-fastpow(2,n-1)+MOD)%MOD << '\n';
}