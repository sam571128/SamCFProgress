#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5e4+5;
vector<int> adj[N];
int visited[N];


void dfs(int u, ll & edges, ll & vertex){
	visited[u] = true;
	edges += adj[u].size();
	vertex += 1;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v,edges,vertex);
		}
	}
}
int main(){
	fastio
	int n,m;
	cin >> n >> m;
	while(m--){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1;i <= n;i++){
		if(!visited[i]){
			ll edges = 0, vertex = 0;
			dfs(i,edges,vertex);
			if(edges!=vertex*(vertex-1)){
				cout << "NO" << "\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}