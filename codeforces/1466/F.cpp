#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e5+5, MOD = 1e9+7;
int dsu[N];

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res * n % MOD;
		n = n*n %MOD;
		p>>=1;
	}
	return res;
}

int find(int u){
	return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}

void unite(int u, int v){
	u = find(u), v = find(v);
	if(u==v) return;
	dsu[u] = v;
}

signed main(){
	fastio
	iota(dsu,dsu+N,0);
	int n,m;
	cin >> n >> m;
	vector<int> ans;
	for(int i = 0;i < n;i++){
		int k;
		cin >> k;
		int a,b = 0;
		cin >> a; if(k>1) cin >> b;
		if(find(a)!=find(b)) ans.push_back(i+1);
		unite(a,b);
	}
	cout << fastpow(2,ans.size()) << " " << ans.size() << "\n";
	for(auto x : ans) cout << x << " ";
}