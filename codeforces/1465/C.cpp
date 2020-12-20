#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int adj[N], visited[N];

int dfs(int u){
	if(!adj[u]) return 0;
	if(visited[u]) return 1;
	visited[u] = 1;
	int tmp = dfs(adj[u]);
	adj[u] = 0;
	return tmp+1;
}

void solve(){
	int n,m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 1;i <= n;i++) adj[i] = 0, visited[i] = 0;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		if(u!=v) adj[u] = v;
	}
	for(int i = 1;i <= n;i++){
		ans += dfs(i);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}