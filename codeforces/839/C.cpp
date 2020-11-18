#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
double ans[N];

void dfs(int u, int par = -1, int t = 0){
	bool done = false;
	int cnt = 0;
	for(auto v : adj[u]){
		if(v!=par) done = 1, dfs(v,u,t+1), ans[u] += ans[v], cnt++;
	}
	
	if(done) ans[u]/=cnt,ans[u]++;
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout << setprecision(10) << fixed << ans[1] << "\n";
}