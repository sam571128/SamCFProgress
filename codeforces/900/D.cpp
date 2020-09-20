#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

unordered_map<int,int> m;
const int MOD = 1e9+7;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

int solve(int a){
	if(a==1) return 1;
	if(m.count(a)) return m[a];
	int ans = fastpow(2,a-1);

	for(int i = 2;i*i <= a;i++){
		if(a%i==0){
			ans -= solve(a/i);
			if(a/i!=i) ans -= solve(i);
		}
	}
	ans--;

	m[a] = (ans%MOD+MOD)%MOD;
	return m[a];
}

void solve(){
	int x,y;
	cin >> x >> y;
	if(y%x!=0){
		cout << 0 << "\n";
		return;
	}
	cout << solve(y/x) << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}