#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int deg[N];
int order[N];

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 0;i <= n;i++) adj[i].clear(), deg[i] = 0, order[i] = -1;
	vector<pair<int,int>> undirected, directed;
	for(int i = 0;i < m;i++){
		int t,u,v;
		cin >> t >> u >> v;
		if(t==1){
			adj[u].push_back(v);
			deg[v]++;
			directed.push_back({u,v});
		}else{
			undirected.push_back({u,v});
		}
	}
	int cnt = 0;
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(deg[i]==0) q.push(i);
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		order[u] = cnt;
		for(auto x : adj[u]){
			if(--deg[x]==0) q.push(x);
		}
		cnt++;
	}
	for(int i = 1;i <= n;i++){
		if(deg[i]!=0){
			cout << "NO\n";
			return;
		}
	}
	for(auto x : undirected){
		if(order[x.first]>order[x.second]){
			directed.push_back({x.second,x.first});
		}else{
			directed.push_back({x.first,x.second});
		}
	}
	cout << "YES\n";
	for(auto x : directed){
		cout << x.first << " " << x.second << "\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}