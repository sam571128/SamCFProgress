#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>
#include <bits/extc++.h>


using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(x,m,n) for(int x = m; x < n;x++)
#define repp(x,m,n) for(int x = m; x <= n;x++)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update, ordered_set>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//find_by_order(), order_of_key();
#define MOD 1000000007

const int N = 1e6+5;

void solve();

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

/*
int fact[N];
void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++)
		fact[i] = fact[i-1]*i%MOD;
}

int nCr(int n, int r){
	if(n < r) return 0;
	return fact[n]*fastpow(fact[n-r],MOD-2)*fastpow(fact[r],MOD-2)
}
*/



signed main(){
	fastio
	int t = 1;
	//cin >> t;
	rep(i,0,t) solve();
}

int k;

set<int> adj[N];
int visited[N], now;

void dfs(int u){
	if(adj[u].size() >= k) return;
	if(visited[u]) return;
	visited[u] = 1;
	now--;
	for(auto v : adj[u]){
		adj[v].erase(u);
		dfs(v);
	}
}

vector<pair<int,int>> edges;

void solve(){
	int n,m;
	cin >> n >> m >> k;
	now = n;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		edges.push_back({u,v});
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for(int i = 1;i <= n;i++){
		dfs(i);
	}
	int ans[m];
	ans[m-1] = now;
	for(int i = m-1;i;i--){
		auto [u,v] = edges[i];
		adj[u].erase(v);
		adj[v].erase(u);
		dfs(u);
		dfs(v);
		ans[i-1] = now;
	}
	for(auto x : ans) cout << x << "\n";
}