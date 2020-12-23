#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N], adj2[N];
int vis[N];

void dfs(int u){
	vis[u] = true;
	for(auto v : adj[u]){
		if(!vis[v]){
			dfs(v); 
			adj2[u].push_back(v), adj2[v].push_back(u);
		}
	}
	adj[u].clear();
}

vector<int> path;
void dfs2(int u, int p){
	path.push_back(u);
	for(auto v : adj2[u]){
		if(v==p) continue;
		dfs2(v,u);
		path.push_back(u);
	}
}

signed main(){
	//fastio
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	memset(vis,0,sizeof vis);
	dfs2(1,-1);
	int ma = (2*n+k-1)/k;
	vector<vector<int>> ans;
	ans.push_back(vector<int>());
	for(auto x : path){
		if(ans.back().size() >= ma){
			ans.push_back(vector<int>());
		}
		ans.back().push_back(x);
	}
	for(auto v : ans){
		cout << v.size() << " ";
		for(auto x : v){
			cout << x << " ";
		}
		cout << "\n";
	}
	for(int i = 0;i < k-ans.size();i++){
		cout << 1 << " " << 1 << "\n";
	}
}