#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
int dep[N], dp[N], arr[N][20];
//dp[i] is the size of the subtree of root i

void dfs(int u, int p = -1){
	dp[u] = 1;
	for(auto v : adj[u]){
		if(v!=p){
			arr[v][0] = u;
			dep[v] = dep[u]+1;
			dfs(v,u);
			dp[u] += dp[v];
		}
	}
}

void build(){
	for(int i = 0;i < 20-1;i++){
		for(int j = 0;j < N;j++){
			arr[j][i+1] = arr[arr[j][i]][i]; 
		}
	}
}

int jump(int u, int dis){
	for(int i = 0;(1<<i) <= dis;i++){
		if(dis&(1<<i)){
			dis ^= (1<<i);
			u = arr[u][i];
		}
	}
	return u;
}

int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u,v);
	u = jump(u,dep[u]-dep[v]);
	if(u==v) return u;
	for(int i = 19;~i;i--){
		if(arr[u][i]!=arr[v][i]){
			u = arr[u][i], v = arr[v][i];
		}
	}
	return arr[u][0];
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	build();
	int q;
	cin >> q;
	while(q--){
		int x,y;
		cin >> x >> y;
		if(x==y){
			cout << n << "\n";
		}else if((dep[x]+dep[y])&1){
			cout << 0 << "\n";
		}else{
			int l = lca(x,y);
			if(dep[x]==dep[y]){
				int a = jump(x,dep[x]-dep[l]-1), b = jump(y,dep[y]-dep[l]-1);
				cout << n-dp[a]-dp[b] << "\n";
			}else{
				if(dep[x] < dep[y]) swap(x,y);
				int dis = dep[x]+dep[y]-2*dep[l];
				int a = jump(x,dis/2), b = jump(x,dis/2-1);
				cout << dp[a]-dp[b] << "\n";
			}
		}
	}
	
}