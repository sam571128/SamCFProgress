#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5 + 5;
int arr[N], jump[N][20], val[N], dep[N], w[N];
vector<int> adj[N];

void dfs1(int u){
	//Build binary lifting
	for(auto v : adj[u]){
		dep[v] = dep[u] + w[v];
		dfs1(v);
		jump[v][0] = u;
	}
}

void dfs2(int u){
	int tmp = val[u], uu = u; 
	for(int i = 19;~i;i--){
		if(dep[uu] - dep[jump[u][i]] <= tmp)
			u = jump[u][i];
	}
	//We need to add 1 to the path from uu to u
	if(u!=uu) arr[jump[u][0]]--, arr[jump[uu][0]]++;
	u = uu;
	for(auto v : adj[u]){
		dfs2(v);
	}
}

void dfs3(int u){
	//Get the answer from all subtrees
	for(auto v : adj[u]){
		dfs3(v);
		arr[u] += arr[v];
	}
}

signed main(){
	fastio
	dep[1] = 0;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> val[i];
	for(int v = 2;v <= n;v++){
		int u, ww;
		cin >> u >> ww;
		w[v] = ww;
		adj[u].push_back(v);
	}

	dfs1(1);
	//Build binary lifting
	for(int i = 1;i < 20;i++){
		for(int u = 1;u <= n;u++){
			jump[u][i] = jump[jump[u][i-1]][i-1];
		}
	}

	dfs2(1);
	dfs3(1);
	for(int i = 1;i <= n;i++) cout << arr[i] << " ";
}