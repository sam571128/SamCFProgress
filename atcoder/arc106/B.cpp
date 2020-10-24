#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int vis[N], a[N], b[N];
int add1, add2;

void dfs(int u){
	vis[u] = true;
	add1 += a[u], add2 += b[u];
	for(auto v : adj[u]){
		if(!vis[v]) dfs(v);
	}
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> b[i];
	while(m--){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1;i <= n;i++){
		add1 = 0, add2 = 0;
		if(!vis[i]) dfs(i);
		if(add1!=add2){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}