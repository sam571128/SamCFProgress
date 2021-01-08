#include <bits/stdc++.h>

//#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
vector<int> adj[N];
int dp[N];

void dfs(int u, int p = -1, int n = 1e9+7){
	dp[u] = min(n,u);
	for(auto v : adj[u]){
		if(v!=p) dfs(v,u,dp[u]);
	}
}

signed main(){
	fastio
	int n,q;
	cin >> n >> q;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	q--;
	int t, z, last = 0, tmp,x;
	cin >> t >> z;
	x = (last+z)%n+1;
	tmp = x;
	dfs(x);
	//for(int i = 1;i <= n;i++) cout << dp[i] << " ";
	//out << "\n";
	while(q--){
		cin >> t >> z;
		x = (z+last)%n+1;
		if(t==1){
			tmp = min(tmp,dp[x]);
		}else{
			cout << (last=min(tmp,dp[x])) << "\n";	
		}
	}
}