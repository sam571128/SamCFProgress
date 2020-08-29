#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int visited[N];

int dfs(int u){
	visited[u] = true;
	int res = 1;
	for(auto v : adj[u]){
		if(!visited[v]) res += dfs(v);
	}
	return res;
}

void solve(){
	int ans = 0;
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1;i <= n;i++){
		ans = max(ans,dfs(i));
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}