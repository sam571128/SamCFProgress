//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	vector<int> adj[n+1];
	int deg[n+1], ans[n+1];
	memset(ans,0,sizeof ans);
	memset(deg,0,sizeof deg);
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		deg[v]++;
	}
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(!deg[i]) q.push(i); 
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v : adj[u]){
			ans[v] = max(ans[v], ans[u]+1); 
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
	cout << *max_element(ans,ans+n+1) << "\n";
}