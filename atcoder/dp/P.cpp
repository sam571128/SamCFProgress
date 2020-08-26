#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N =1e5+5;
vector<int> adj[N];
const int MOD = 1e9+7;

int dp[N][2];

void dfs(int u, int par = -1){
	int a = 1, b = 1;
	for(auto v : adj[u]){
		if(v==par) continue;
		dfs(v,u);
		a = (a*(dp[v][0]+dp[v][1]))%MOD;
		b = (b*dp[v][0])%MOD;
	}
	dp[u][0] = a;
	dp[u][1] = b;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//0->black, 1-white
	dfs(1);
	cout << (dp[1][0] + dp[1][1])%MOD << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}