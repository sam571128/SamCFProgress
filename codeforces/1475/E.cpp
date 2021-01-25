#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;
const int N = 1e3+5;
int fact[N];

void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++)
		fact[i] = fact[i-1]*i%MOD;
}

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}


int nCr(int n, int r){
	return fact[n]*fastpow(fact[n-r],MOD-2)%MOD*fastpow(fact[r],MOD-2)%MOD;
}


void solve(){
	vector<int> v;
	int n,m;
	cin >> n >> m;
	int cnt[n+1] = {};
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}
	int tt = m;
	for(int i = n;i;i--){
		m-=cnt[i];
		if(cnt[i]) v.push_back(cnt[i]);
		if(m <= 0) break;
	}
	if(m > 0) cout << 0 << "\n";
	else{
		m = tt;
		int ans = 1;
		for(int i = 0;i < v.size()-1;i++) m-=v[i];
		//cout << v.back() << " " << m << "\n";
		ans = ans*nCr(v.back(),m)%MOD;
		cout << ans << "\n";
	}
}

signed main(){
	init();
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}