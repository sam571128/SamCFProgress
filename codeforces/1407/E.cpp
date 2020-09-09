#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e5+5, INF = 1e18;
vector<pair<int,int>> adj[N];
vector<pair<int,int>> radj[N];
int visited[N];
signed main(){
	fastio
	int n, m;
	cin >> n >> m;
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		radj[v].push_back({u,w});
	}
	vector<vector<int>> dp(n+1,vector<int>(2,INF));
	dp[n][0] = dp[n][1] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,n});
	while(!pq.empty()){
		auto [dist,u] = pq.top(); pq.pop();
		if(u==1) break;
		if(visited[u]) continue;
		visited[u] = true;
		for(auto [v,w] : radj[u]){
			int tmp = max(dp[v][0],dp[v][1]);
			dp[v][w] = min(dp[v][w], dist+1);
			if(max(dp[v][0],dp[v][1]) < tmp) pq.push({max(dp[v][0],dp[v][1]),v});
		}
	}
	//for(int i = 1;i <= n;i++) cout << dp[i][0] << " " << dp[i][1] << "\n";
	memset(visited,0,sizeof visited);
	vector<int> ans(n+1,0);
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(visited[u]) continue;
		visited[u] = true;
		ans[u] = (dp[u][0] > dp[u][1] ? 0 : 1);
		for(auto [v,w] : adj[u]){
			if(ans[u]!=w||visited[v]) continue;
			q.push(v);
		}
	}
	if(dp[1][ans[1]] > n) cout << -1 << "\n";
	else cout << dp[1][ans[1]] << "\n";
	for(int i = 1;i <= n;i++) cout << ans[i];
}