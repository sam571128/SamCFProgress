#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct edge{
	int u,v;
};

const int N = 2e5+5;
vector<int> adj[N];
vector<edge> edges;
int color[N];
bool ok = true;

void dfs(int u, int c){
	color[u] = c;
	for(auto v : adj[u]){
		if(!~color[v]) dfs(v,c^1);
		else if(color[v]==color[u]) ok = false;
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	while(m--){
		int u,v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		edges.push_back({u,v});
	}
	memset(color,-1,sizeof color);
	dfs(1,0);
	if(!ok){
		cout << "No" << "\n";
		return;
	}
	cout << "Yes\n";
	for(auto x : edges){
		cout << (color[x.u]>color[x.v]);
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}