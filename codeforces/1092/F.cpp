#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int val[N], dp[N];
vector<int> adj[N];
int ans = 0, now = 0;

void dfs(int u, int par, int dep){
	now += dep*val[u];
	dp[u] = val[u];
	for(auto v : adj[u]){
		if(v!=par){
			dfs(v,u,dep+1);
			dp[u] += dp[v];
		}
	}
}

void dfs2(int u, int par){
	ans = max(ans, now);
	for(auto v : adj[u]){
		if(v!=par){
			now -= dp[v];
			dp[u] -= dp[v];
			now += dp[u];
			dp[v] += dp[u];
			dfs2(v,u);
			dp[v] -= dp[u];
			now -= dp[u];
			dp[u] += dp[v];
			now += dp[v];
		}
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> val[i];
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1,0);
	dfs2(1,-1);
	cout << ans << "\n";
}