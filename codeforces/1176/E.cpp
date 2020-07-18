#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<vector<int>> adj;
bool visited[N];
int d[N];

void dfs(int u, int c = 0){
	visited[u] = true;
	d[u] = c;
	for(auto v : adj[u]){
		if(!visited[v]) dfs(v,c^1);
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	adj = vector<vector<int>>(n+1);
	memset(visited,0,sizeof visited);
	for(int i = 0;i < m;i++){	
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	vector<int> c1,c2;
	for(int i = 1;i <= n;i++){
		if(d[i]) c1.push_back(i);
		else c2.push_back(i);
	}
	if(c1.size()>c2.size()){
		cout << c2.size() << "\n";
		for(auto x : c2) cout << x << " ";
	}else{
		cout << c1.size() << "\n";
		for(auto x : c1) cout << x << " ";
	}
	cout << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}