#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<vector<int>> adj;
void solve(){
	int n,a,b,da,db;
	cin >> n >> a >> b >> da >> db;
	adj.clear();
	adj.resize(n+1,vector<int>(0));
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(da*2>=db){
		cout << "Alice\n";
		return;
	}
	queue<int> bfs;
	int dist[n+1];
	memset(dist,0x3f3f3f,sizeof dist);
	dist[a] = 0;
	bfs.push(a);
	while(!bfs.empty()){
		int u = bfs.front(); bfs.pop();
		for(auto v : adj[u]){
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u]+1;
				bfs.push(v);
			}
		}
	}
	if(dist[b] <= da){
		cout << "Alice\n";
		return;
	}
	int far = -1, tmp = 0;
	for(int i = 1;i <= n;i++){
		if(dist[i] > tmp){
			tmp = dist[i];
			far = i;
		}
	}
	memset(dist,0x3f3f3f,sizeof dist);
	dist[far] = 0;
	bfs.push(far);
	while(!bfs.empty()){
		int u = bfs.front(); bfs.pop();
		for(auto v : adj[u]){
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u]+1;
				bfs.push(v);
			}
		}
	}
	tmp = 0;
	for(int i = 1;i <= n;i++){
		if(dist[i] > tmp){
			tmp = dist[i];
		}
	}
	if(tmp <= 2*da){
		cout << "Alice\n";
	}else{
		cout << "Bob\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}