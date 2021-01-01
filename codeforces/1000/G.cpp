#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5;
vector<pair<int,int>> adj[N];
int val[N], dp[N], head[N], sz[N], dp2[N], heavy[N], dep[N], sum[N], fa[N], to[N];
//dp[u] is the maximum two-path in the subtree
//dp2[u] is the maxiumum two-path if we move up from u and come back
//head, sz, heavy is for heavy light decomposition to find LCA
//sum[u] is the maximum value from root to u

void dfs1(int u, int p){
	//cout << u << "\n";
	int mx = 0;
	dp[u] = val[u], sz[u] = 1;
	for(auto [v,w] : adj[u]){
		if(v==p) continue;
		dep[v] = dep[u] + 1;
		fa[v] = u;
		to[v] = w;
		dfs1(v,u);
		sz[u] += sz[v];
		dp[u] += max((int)0,dp[v]-w*2);
		if(sz[v] > mx) heavy[u] = v, mx = sz[v];
	}
}

void dfs2(int u, int h){
	head[u] = h;
	sum[u] = sum[fa[u]]+dp[fa[u]]-max((int)0,dp[u]-to[u]*2)-to[u];
	dp2[u] = max((int)0,dp2[fa[u]]+dp[fa[u]]-max((int)0,dp[u]-to[u]*2)-to[u]-to[u]);
	if(heavy[u]!=0) dfs2(heavy[u],h);
	for(auto [v,w] : adj[u]){
		if(v==fa[u]||v==heavy[u]) continue;
		dfs2(v,v);
	}
}

int LCA(int u, int v){
	while(head[u]!=head[v]){
		dep[head[u]] > dep[head[v]] ? u = fa[head[u]] : v = fa[head[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

signed main(){
	fastio
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> val[i];
	for(int i = 2;i <= n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dfs1(1,1);
	dfs2(1,1);
	cout << "\n";
	while(q--){
		int u,v;
		cin >> u >> v;
		int l = LCA(u,v);
		//cout << u << " " << v << " " << l << "\n";
		cout << (sum[u]-sum[l])+(sum[v]-sum[l])+dp[u]+dp[v]-dp[l]+dp2[l] << "\n";
	}
}