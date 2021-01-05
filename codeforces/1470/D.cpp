#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
vector<int> adj[N], ans;
int visited[N];

void dfs1(int u){
	//Check if the graph is connected
	if(visited[u]) return;
	visited[u] = 1;
	for(auto v : adj[u]){
		if(!visited[v]) dfs1(v);
	}
}

void dfs2(int u, int c = 1){
	if(visited[u]) return;
	visited[u] = 1;
	if(c) ans.push_back(u);
	for(auto v : adj[u]){
		if(!visited[v]) dfs2(v,c^1);
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	ans.clear();
	for(int i = 0;i <= n;i++) adj[i].clear(), visited[i] = 0;
	while(m--){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1);
	for(int i = 1;i <= n;i++) if(!visited[i]){
		cout << "NO\n";
		return;
	}
	for(int i = 0;i <= n;i++) visited[i] = 0;
	
	queue<int> q;
	visited[1] = 1;
	q.push(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(visited[u]==2) continue;
		if(visited[u]==1){
			visited[u] = 2;
			for(auto v : adj[u]){
				if(!visited[v]) visited[v] = 3, q.push(v);
				if(visited[v]==1||visited[v]==3) visited[v] = 3;
			}
		}else{
			for(auto v : adj[u]){
				if(!visited[v]){
					visited[v] = 1;
					q.push(v);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++) if(visited[i] == 2) ans.push_back(i);
	cout << "YES\n";
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x << " ";
	cout << "\n";
}

signed main(){
	//fastio
	int t;
	cin >> t;
	while(t--) solve();
}
	