#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int deg[N], cnt[N];

void solve(){
	int n;
	cin >> n;
	for(int i = 0;i <= n;i++) adj[i].clear(), deg[i] = 0, cnt[i] = 1;
	for(int i = 0;i < n;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(deg[i]==1) q.push(i);
	}
	int ans = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		deg[u]--;
		for(auto v : adj[u]){
			if(deg[v]<=0) continue;
			deg[v]--;
			cnt[v]+=cnt[u];
			cnt[u] = 0;
			if(deg[v]==1) {
				q.push(v);
			}
		}
	}
	for(int u = 1;u <= n;u++){	
		ans += cnt[u]*(cnt[u]-1)/2;
		ans += cnt[u]*(n-cnt[u]);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}