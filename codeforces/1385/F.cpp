#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int leaves[N];
bool vis[N];
int sz[N];

void solve(){
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) adj[i].clear(), leaves[i] = 0, vis[i] = false, sz[i] = 0;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		sz[u]++;
		sz[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(k==1){
		cout << n-1 << "\n";
		return;
	}
	for(int i = 1;i <= n;i++){
		for(auto v : adj[i]){
			//cout << v << " " << adj[v].size() << "\n";
			if(adj[v].size()==1) leaves[i]++;
		}
	}
	int ans = 0;
	bool ok = false;
	while(!ok){
		ok = true;
		for(int i = 1;i <= n;i++){
			//cout << i << " " << leaves[i] << "\n";
			if(leaves[i] >= k){
				ok = false;
				ans+= (leaves[i]-leaves[i]%k)/k;
				sz[i]-=(leaves[i]-leaves[i]%k);
				leaves[i] = leaves[i]%k;
				if(sz[i]==1){
					vis[i] = true;
					for(auto u : adj[i]){
						if(!vis[u]) leaves[u]++;
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}