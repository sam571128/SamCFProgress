#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 4e5+5;
vector<int> adj[N];
int visited[N], cnt = 0, cnt2, cnt3, ans;

void dfs(int u, int p = -1){
	visited[u] = 1;
	cnt3++;
	for(auto v : adj[u]){
		if(v!=p) cnt2++;
		if(!visited[v]) dfs(v,u);
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	set<int> nodes;
	for(int i = 0;i < n;i++){
		int u,v;
		cin >> u >> v;
		nodes.insert(u);
		nodes.insert(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(auto x : nodes){
		if(!visited[x]) cnt2 = cnt3 = 0, dfs(x), ans += min(cnt2,cnt3);
	}
	cout << ans << "\n";
}