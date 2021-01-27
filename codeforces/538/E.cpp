#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int dp[N], dep[N], cnt = 0;

void dfs1(int u, int p = -1){
	if(adj[u].size()<1||(adj[u].size()==1&&p!=-1)){
		dp[u] = 1, cnt++;
		return;
	}
	if(dep[u]&1^1){
		dp[u] = N;
		for(auto v : adj[u]){
			if(v==p) continue;
			dep[v] = dep[u]+1;
			dfs1(v,u);
			dp[u] = min(dp[u],dp[v]);
		}
	}else{
		for(auto v : adj[u]){
			if(v==p) continue;
			dfs1(v,u);
			dep[v] = dep[u]+1;
			dp[u] += dp[v];
		}
	}
}

void dfs2(int u, int p = -1){
	if(adj[u].size()<1||(adj[u].size()==1&&p!=-1)){
		dp[u] = 1;
		return;
	}
	if(dep[u]&1){
		dp[u] = N;
		for(auto v : adj[u]){
			if(v==p) continue;
			dfs2(v,u);
			dp[u] = min(dp[u],dp[v]);
		}
	}else{
		dp[u] = 0;
		for(auto v : adj[u]){
			if(v==p) continue;
			dfs2(v,u);
			dp[u] += dp[v];
		}
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1);
	cout << cnt-dp[1]+1 << " ";
	dfs2(1);
	cout << dp[1] << "\n";
}