#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<vector<int>> adj;

vector<int> Centroid(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
            sz[u] = 1;
            bool is_centroid = true;
            for (auto v : g[u]) if (v != prev) {
                    dfs(v, u);
                    sz[u] += sz[v];
                    if (sz[v] > n / 2) is_centroid = false;
            }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(u);
    };
    dfs(1, -1);
    return centroid;
}

void solve(){
	int n;
	cin >> n;
	adj.clear();
	adj.resize(n);
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> c = Centroid(adj);
	if(c.size()==1){
		cout << c[0]+1 << " " << adj[c[0]][0]+1 << "\n";
		cout << c[0]+1 << " " << adj[c[0]][0]+1 << "\n";
		return;
	}
	int v = -1;
	for(auto x : adj[c[0]]){
		if(x!=c[1]){
			v = x;
			break;
		}
	}
	cout << c[0]+1 << " " << v+1 << "\n";
	cout << c[1]+1 << " " << v+1 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}