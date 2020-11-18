#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+50;
vector<int> adj[N];
int vis[N];

void dfs(int u){
	vis[u] = true;
	for(auto v : adj[u]) if(!vis[v]) dfs(v);
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		string s;
		cin >> s;
		for(char c : s){
			adj[i].push_back(N-(c-'a')-1);
			adj[N-(c-'a')-1].push_back(i);
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(!vis[i]) ans++, dfs(i);
	}
	cout << ans << "\n";
}