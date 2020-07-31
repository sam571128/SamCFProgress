#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int walked[N], p[N], h[N], b[N];
bool ans;

void dfs(int u = 1, int a = -1){
	walked[u] = p[u];
	for(auto v : adj[u]){
		if(v==a) continue;
		dfs(v,u);
		walked[u] += walked[v];
	}
	if(walked[u] < h[u]||walked[u]&1^h[u]&1) ans = false;
	b[u] = (walked[u]-h[u])/2;
	int tmp = 0;
	for(int v : adj[u])
		if(v!=a) tmp+=b[v];
	if(b[u]>walked[u]||b[u] > tmp+p[u]) ans = false;
}

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 0;i <= n;i++) adj[i].clear(), b[i] = 0;
	for(int i = 1;i <= n;i++) cin >> p[i];
	for(int i = 1;i <= n;i++) cin >> h[i];	
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ans = 1;
	dfs();
	cout << (ans ? "YES\n" : "NO\n");
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}