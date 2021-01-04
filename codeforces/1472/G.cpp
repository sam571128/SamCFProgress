#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N], adj2[N];
int visited[N], dis[N], ans[N];
void solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 0;i <= n;i++) adj[i].clear(), adj2[i].clear(), dis[i] = 1e18, visited[i] = 0, ans[i] = 1e18;
	while(m--){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}
	dis[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v : adj[u]){
			if(dis[v] > dis[u]+1){
				dis[v] = dis[u]+1;
				q.push(v);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		ans[i] = dis[i];
		for(auto v : adj[i]){
			ans[i] = min(ans[i],dis[v]);
		}
	}
	for(int i = 1;i <= n;i++) q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v : adj2[u]){
			if(dis[u] > dis[v]&&ans[v] > ans[u]){
				ans[v] = min(ans[u],ans[v]);
				q.push(v);
			}
		}
	}
	for(int i = 1;i <= n;i++) cout << ans[i] << " ";
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}