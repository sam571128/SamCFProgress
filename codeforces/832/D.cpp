#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
vector<int> adj[N];
int par[N], dep[N], heavy[N], head[N];

int dfs(int u){
	int sz = 1;
	int maxsz = 0;
	for(auto v : adj[u]){
		if(v==par[u]) continue;
		par[v] = u, dep[v] = dep[u] + 1;
		int childsz = dfs(v);
		sz += childsz;
		if(childsz > maxsz)
			maxsz = childsz, heavy[u] = v;
	}
	return sz;
}

void decompose(int u, int h){
	head[u] = h;
	if(heavy[u]!=0)
		decompose(heavy[u],h);
	for(auto v : adj[u]){
		if(v!=par[u]&&v != heavy[u])
			decompose(v,v);
	}
}

int lca(int u, int v){
	while(head[u]!=head[v]){
		if(dep[head[u]] > dep[head[v]])
			u = par[head[u]];
		else 
			v = par[head[v]];
	}
	return dep[u] > dep[v] ? v : u;
}


signed main(){
	fastio
	int n, m;
	cin >> n >> m;
	for(int i = 2;i <= n;i++){
		int u;
		cin >> u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}
	dfs(1);
	decompose(1,1);
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		int dis[3];
		dis[0] = (dep[a]+dep[b]-dep[lca(a,b)]*2);
		dis[1] = (dep[a]+dep[c]-dep[lca(a,c)]*2);
		dis[2] = (dep[b]+dep[c]-dep[lca(b,c)]*2);
		sort(dis,dis+3);
		cout << (dis[2]+dis[1]-dis[0])/2+1 << "\n";
	}
}