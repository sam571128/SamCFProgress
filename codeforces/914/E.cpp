#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
set<int> adj[N];
int sz[N], par[N], ans[N], cnt[1<<20], dp[N], tmpcnt[N];
int arr[N];

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

void dfs2(int u, int p, int mask, int x){
	//Calculate the number of masks in the subtree with root u
	cnt[mask] += x;
	for(auto v : adj[u]) if(v!=p) {
		//cout << u << " to " << v << " " << mask << " to " << (mask^(1<<arr[v])) << "\n";
		dfs2(v,u,mask^(1<<arr[v]),x);
	}
}

void dfs3(int u, int p, int mask, int c){
	//Add all values of paths to dp[u]
	dp[u] = cnt[mask];
	for(int i = 0;i < 20;i++) dp[u] += cnt[mask^(1<<i)];

	//If the mask xor the val of the root is 0 or 2^n, then there is a path
	if(__builtin_popcount(mask^(1<<arr[c])) <= 1) tmpcnt[c]++; 

	for(auto v : adj[u]) if(v!=p) dfs3(v,u,mask^(1<<arr[v]),c);
}

void dfs4(int u, int p){
	//Add all answers from subtree to the root
	for(auto v : adj[u]){
		if(v==p) continue;
		dfs4(v,u);
		dp[u] += dp[v];
		dp[v] = 0;
	}
	if(p==0) ans[u] += (dp[u]+tmpcnt[u])/2;
	else ans[u] += dp[u];
}

void build(int u){
	int n = dfs(u,0);
	u = centroid(u,0,n);
	int mask = (1 << arr[u]);
	dfs2(u,0,mask,1);
	for(auto v : adj[u]){
		dfs2(v,u,mask^(1<<arr[v]),-1);
		dfs3(v,u,1<<arr[v],u);
		dfs2(v,u,mask^(1<<arr[v]),1);
	}
	dfs4(u,0);
	dp[u] = 0;
	ans[u]++;
	dfs2(u,0,mask,-1);
	vector<int> tmp(adj[u].begin(),adj[u].end());
	for(auto v : tmp){
 		adj[u].erase(u), adj[v].erase(u);
		build(v);
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for(int i = 1;i <= n;i++){
		char c;
		cin >> c;
		arr[i] = c-'a';
	}
	build(1);
	for(int i = 1;i <= n;i++) cout << ans[i] << " ";
}