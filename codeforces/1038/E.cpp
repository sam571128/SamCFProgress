#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct edge{
	int u, v, w, can;
	bool operator < (edge b){
		return w < b.w;
	}
};
vector<edge> edges;

vector<int> adj[5];
int deg[5], tmp, ans, vis[5];

void dfs(int u){
	for(auto idx : adj[u]){
		if(!edges[idx].can) continue;
		edges[idx].can = 0;
		tmp += edges[idx].w;
		if(edges[idx].u!=u) swap(edges[idx].u,edges[idx].v);
		dfs(edges[idx].v);
	}
}

void get(int idx){
	for(int i = 1;i <= 4;i++){
		tmp = 0;
		memset(vis,0,sizeof vis);
		for(auto &e : edges) e.can = 1;
		if(~idx) edges[idx].can = 0;
		dfs(i);
		ans = max(tmp,ans);
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int u,w,v;
		cin >> u >> w >> v;
		adj[u].push_back(edges.size());
		adj[v].push_back(edges.size());
		deg[u]++, deg[v]++;
		edges.push_back({u,v,w,1});
	}
	int degsum = 0;
	for(int i = 1;i <= 4;i++) degsum += (deg[i]&1);
	if(degsum/2 <= 1){
		get(-1);
	}
	for(int i = 0;i < edges.size();i++){
		auto [u,v,w,can] = edges[i];
		if(u==v) continue;
		degsum -= (deg[u]&1)+(deg[v]&1);
		deg[u]--, deg[v]--;
		degsum += (deg[u]&1)+(deg[v]&1);
		if(degsum/2 <= 1) get(i);
		degsum -= (deg[u]&1)+(deg[v]&1);
		deg[u]++, deg[v]++;
		degsum += (deg[u]&1)+(deg[v]&1);
	}
	cout << ans << "\n";
}