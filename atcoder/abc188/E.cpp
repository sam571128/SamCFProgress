#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int deg[N], dp[N], ans[N], val[N];

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> val[i];
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		deg[v]++;
	}
	memset(dp,0x3f3f3f,sizeof dp);
	memset(ans,-0x3f3f3f,sizeof ans);
	vector<int> arr;
	queue<int> q;
	for(int i = 1;i <= n;i++)
		if(deg[i]==0) q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		arr.push_back(u);
		for(auto v : adj[u]){
			deg[v]--;
			if(deg[v]==0) q.push(v);
		}
	}
	for(auto u : arr){
		dp[u] = min(dp[u],val[u]);
		for(auto v : adj[u]){
			dp[v] = min(dp[v],dp[u]);
			ans[v] = max(ans[v],val[v]-dp[u]);
		}
	}
	cout << *max_element(ans,ans+N) << "\n";
}