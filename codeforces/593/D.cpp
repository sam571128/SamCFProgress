#pragma optimize("O3")
#pragma optimize("unroll-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5, INF = 1e18+5;
vector<pair<int,int>> adj[N];
int par[N], dp[N][20], d[N], dep[N];
vector<pair<int,int>> edge;

void dfs(int u){
	for(auto [v,w] : adj[u]){
		if(v==par[u]) continue;
		par[v] = u;
		dp[v][0] = u;
		d[v] = w;
		dep[v] = dep[u]+1;
		dfs(v);
	}
}

int lca(int u, int v){
	if(dep[u] < dep[v]){
		swap(u,v);
	}
	int jump = dep[u] - dep[v];
	for(int i = 0;i < 20;i++){
		if(jump&(1<<i))
			u = dp[u][i];
	}
	if(u==v) return u;
	for(int i = 19;~i;i--){
		if(dp[u][i]!=dp[v][i])
			u = dp[u][i], v = dp[v][i];
	}
	return dp[u][0];
}

signed main(){
	fastio
	int n,q;
	cin >> n >> q;
	for(int i = 0;i < n-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		edge.push_back({u,v});
	}
	dfs(1);
	for(int i = 1;i < 20;i++){
		for(int j = 1;j <= n;j++){
			dp[j][i] = dp[dp[j][i-1]][i-1];
		}
	}
	while(q--){
		int a;
		cin >> a;
		if(a==1){
			int u,v,val;
			cin >> u >> v >> val;
			int l = lca(u,v);
			while(dep[v] > dep[l]&&val){
				val /= d[v];
				if(d[par[v]] > 1) v = par[v];
				else v = (par[v] = par[par[v]]);
			}
			while(dep[u] > dep[l]&&val){
				val /= d[u];
				if(d[par[u]] > 1) u = par[u];
				else u = (par[u] = par[par[u]]);
			}
			cout << val << "\n";
		}else{
			int id, val;
			cin >> id >> val;
			id--;
			auto [u,v] = edge[id];
			if(dep[u] < dep[v]) swap(u,v);
			d[u] = val;
		}
	}
}