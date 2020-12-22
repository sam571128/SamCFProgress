#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5;
vector<int> adj[N];
int dp[N], ans;

void dfs(int u, int par){
	dp[u] = 1;
	int ma1 = 0, ma2 = 0, cnt = 0;
	for(auto v : adj[u]){
		if(v!=par){
			cnt++;
			dfs(v,u);
			if(dp[v] > ma1) ma2 = ma1, ma1 = dp[v];
			else ma2 = max(dp[v],ma2);
		}
	}
	dp[u] = max(dp[u],ma1 + cnt);
	if(cnt >= 2) ans = max(ans,ma1+ma2+cnt-1+(par!=-1));
	ans = max(ans,dp[u]);
}

void solve(){
	int n;
	cin >> n;
	ans = 1;
	for(int i = 1;i <= n;i++) adj[i].clear(), dp[i] = 0;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}