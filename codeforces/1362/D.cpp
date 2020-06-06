#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e5+5;
int ans[N];
vector<int> adj[N];
vector<int> color[N];
int last[N];

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	while(m--){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1;i <= n;i++){
		int c;
		cin >> c;
		color[c].push_back(i);
		if(c > n){
			cout << -1 << "\n";
			return 0;
		}
	}

	vector<int> result;
	for(int i = 1;i <= n;i++){
		for(auto u : color[i]){
			for(auto v : adj[u])
				last[ans[v]] = u;

			ans[u] = 1;
			while(last[ans[u]] == u){
				ans[u]++;
			}
			if(ans[u]!=i){
				cout << -1 << "\n";
				return 0;
			}
			result.push_back(u);
		}
	}
	for(auto x : result) cout << x << " ";
}