#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;

vector<int> adj[N];
int val[N], dp[N][2]; //1->odd, 0->even;

void dfs(int u){
	dp[u][1] = -1e18;
	if(adj[u].size()==0){
		dp[u][1] = val[u];
		dp[u][0] = 0;
		return;
	}
	for(auto v : adj[u]){
		dfs(v);
		int tmp1 = dp[u][1], tmp2 = dp[u][0];
		dp[u][1] = max(tmp1+dp[v][0],tmp2+dp[v][1]);
		dp[u][0] = max(tmp1+dp[v][1],tmp2+dp[v][0]);
	}
	dp[u][1] = max(dp[u][1],dp[u][0]+val[u]);
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int v = 1;v <= n;v++){
		int u, x;
		cin >> u >> x;
		if(~u) adj[u].push_back(v);
		val[v] = x;
	}
	dfs(1);
	cout << dp[1][1] << "\n";
}
