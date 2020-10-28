#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
set<int> adj[N];
map<int,int> dis[N];
int sz[N], par[N], ans[N];

int dfs(int u, int p){
	sz[u] = 1;
	for(auto v : adj[u]){
		if(v!=p) sz[u] += dfs(v,u);
	}
	return sz[u];
}

int centroid(int u, int p, int n){
	for(auto v : adj[u]){
		if(v!=p) if(sz[v] > n/2) return centroid(v,u,n);
	}
	return u;
}

void dfs2(int u, int p, int c, int d){
	dis[c][u] = d;
	for(auto v : adj[u]){
		if(v!=p) dfs2(v,u,c,d+1);
	}
}

void build(int u, int p){
	int n = dfs(u,p);
	int c = centroid(u,p,n);
	if(p==-1) p = c;
	par[c] = p;
	dfs2(c,p,c,0);

	vector<int> tmp(adj[c].begin(),adj[c].end());
	for(auto v : tmp){
		adj[c].erase(v), adj[v].erase(c);
		build(v,c);
	}
}

void modify(int u){
	for(int v = u; v != 0; v = par[v]) ans[v] = min(ans[v],dis[v][u]);
}

int query(int u){
	int mi = 0x3f3f3f;
	for(int v = u; v != 0; v = par[v]) mi = min(mi,ans[v] + dis[v][u]);
	return mi;
}


signed main(){
	fastio
	memset(ans,0x3f3f3f,sizeof ans);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	build(1,0);
	modify(1);
	while(m--){
		int a,b;
		cin >> a >> b;
		if(a==1) modify(b);
		else cout << query(b) << "\n";
	}
}