#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e3+5;
vector<int> adj[N];
int visited[N], t;

struct edge{
	int v, c;
};


vector<edge> edges;

void dfs(int u){
	//Find Back Edges
	visited[u] = 1; 
	for(auto eid : adj[u]){
		auto &[v,c] = edges[eid];
		if(!visited[v]) dfs(v), c = 1;
		else if(visited[v]==1) c = 2;
		else c = 1;

	}
	visited[u] = 2;
}


signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(edges.size());
		edges.push_back({v,0});
	}
	for(int i = 1;i <= n;i++){
		if(visited[i]) continue;
		dfs(i);	
	}
	int ans = 0;
	for(int i = 0;i < edges.size();i++){
		ans = max(ans,edges[i].c);
	}
	cout << ans << "\n";
	for(int i = 0;i < edges.size();i++){
		cout << edges[i].c << " ";
	}
}