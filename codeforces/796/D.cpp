#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5;
vector<pair<int,int>> adj[N];
int visited[N];

signed main(){
	fastio
	int n,k,d;
	cin >> n >> k >> d;
	int p[k];
	for(auto &x : p) cin >> x;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back({v,i+1});
		adj[v].push_back({u,i+1});
	}
	vector<int> ans;
	queue<pair<int,int>> q;
	
	for(auto x : p) q.push({x,0});
	while(!q.empty()){
		auto [u,par] = q.front(); q.pop();
		if(visited[u]) continue;
		visited[u] = 1;
		for(auto [v,idx] : adj[u]){
			if(v==par) continue;
			if(visited[v]) ans.push_back(idx);
			else q.push({v,u});
		}
	}
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x << " ";
}