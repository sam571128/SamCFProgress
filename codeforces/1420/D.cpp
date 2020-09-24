#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 998244353;
int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

const int N = 5e5+5;
int fact[N];
void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++){
		fact[i] = fact[i-1]*i%MOD;
	}
}


void solve(){
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,1});
		v.push_back({y,-1});
	}
	sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
		return (a.first==b.first ? a.second > b.second : a.first < b.first);
	});
	int ans = 0, cnt = 0;
	for(auto p : v){
		cnt += p.second;
		if(cnt < k||p.second==-1) continue;
		ans = (ans + fact[cnt-1]*fastpow(fact[cnt-k],MOD-2)%MOD*fastpow(fact[k-1],MOD-2)%MOD)%MOD;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	init();
	int t = 1;
	//cin >> t;
	while(t--) solve();
}