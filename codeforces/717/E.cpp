#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int c[N];

void dfs(int u, int par = -1){
	cout << u << " ";
	c[u] *= -1;
	for(auto v : adj[u]){
		if(v==par) continue;
		dfs(v,u);
		cout << u << " ";
		c[u] *= -1;
	}
	if(c[u]==-1){
		if(par!=-1){
			c[par] *= -1, c[u] *= -1;
			cout << par << " " << u << " ";
		}else{
			c[u] *= -1;
			c[adj[u][0]] *= -1;
			cout << adj[u][0] << " " << u << " ";
			if(c[adj[u][0]] == -1){
				cout << adj[u][0] << "\n";
				c[adj[u][0]] *= -1;
			}
			exit(0);
		}
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	c[1] *= -1;
	dfs(1);
}