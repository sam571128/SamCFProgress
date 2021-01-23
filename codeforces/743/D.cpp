#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5, INF = 1e18;
vector<int> adj[N];
int val[N], dp[N], ans = -INF;

void dfs(int u, int par = -1){
	dp[u] += val[u];
	for(int v : adj[u]){
		if(v==par) continue;
		dfs(v,u);
		dp[u] += dp[v];
	}
}

void dfs2(int u, int par = -1){
	int ma1 = -INF, ma2 = -INF;
	for(int v : adj[u]){
		if(v==par) continue;
		dfs2(v,u);
		if(dp[v] > ma1) ma2 = ma1, ma1 = dp[v];
		else if(dp[v] > ma2) ma2 = dp[v];
		dp[u] = max(dp[v],dp[u]);
	}
	if(ma1!=INF&&ma2!=INF) ans = max(ans,ma1+ma2);
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> val[i];
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	dfs2(1);
	if(ans<=-1e16) cout << "Impossible\n";
	else cout << ans << "\n";
}