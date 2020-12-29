#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e4+5;
vector<int> adj[N];
int want[N];
int ans = 0;

void dfs(int u, int p, int c){
	if(c!=want[u]) ans++;
	for(auto v : adj[u]){
		if(v!=p) dfs(v,u,want[u]);
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 2;i <= n;i++){
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	for(int i = 1;i <= n;i++) cin >> want[i];
	dfs(1,1,0);
	cout << ans << "\n";
}