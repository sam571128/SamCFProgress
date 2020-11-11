#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
vector<int> adj[N], vec[N];
int color[N], cnt[N], sz[N];
long long res[N], ans[N];

void dfs_size(int u, int par){
	sz[u] = 1;
    for(auto v : adj[u])
        if(v != par) dfs_size(v,u), sz[u] += sz[v];
}

void update(int &mx, int u, int x){
	ans[cnt[color[u]]] -= color[u];
	cnt[color[u]] += x;
	ans[cnt[color[u]]] += color[u];
	mx = max(cnt[color[u]],mx);
}

int dfs(int u, int par, bool keep){
	int mx = 1, heavy = 0;
	for(auto v : adj[u]){
		if(v != par && sz[v] > mx){
			mx = sz[v];
			heavy = v;
		}
	}
	for(auto v : adj[u]){
		//DFS 輕鏈
		if(v != par && v != heavy){
			//Keep = 0 代表 dfs 後會清除這個子樹的答案
			dfs(v,u,0);
		}
	}
	mx = 0;
	if(heavy){
		mx = max(mx,dfs(heavy,u,1));
		swap(vec[u],vec[heavy]);
	}
	vec[u].push_back(u);
	update(mx,u,1);
	for(auto v : adj[u]){
		if(v != par && v != heavy){
			for(auto x : vec[v]){
				update(mx,x,1);
				vec[u].push_back(x);
			}
		}
	}
	res[u] = ans[mx];
	if(!keep){
		for(auto x : vec[u]){
			update(mx,x,-1);
		}
	}
	return mx;
}

signed main(){
	fastio
	int n; 
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> color[i];
	for(int i = 1,u,v;i < n;i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_size(1,-1);
	dfs(1,-1,0);
	for(int i = 1;i <= n;i++) cout << res[i] << " ";
}