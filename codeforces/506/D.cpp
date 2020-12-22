#pragma optimize(3)
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

const int N = 1e5+5;

gp_hash_table<int,int,chash> dsu[N];

int find(int idx, int u){
	return dsu[idx][u]==u||dsu[idx][u]==0 ? u : dsu[idx][u]=find(idx,dsu[idx][u]);
}

void unite(int idx, int u, int v){
	u = find(idx,u), v = find(idx,v);
	if(u==v) return;
	dsu[idx][u] = v;
}

set<int> adj[N];
vector<pair<int,int>> color[N];
map<pair<int,int>,int> ans;
map<pair<int,int>,int> ans2;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int mm = sqrt(m);
	for(int i = 0;i < m;i++){
		int u,v,c;
		cin >> u >> v >> c;
		color[c].push_back({u,v});
	}

	for(int i = 1;i < N;i++){
		if(color[i].size() <= mm){
			vector<int> tmp;
			for(auto [u,v] : color[i]){
				unite(i,u,v);
				tmp.push_back(u);
				tmp.push_back(v);
			}
			sort(tmp.begin(),tmp.end());
			tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
			for(int j = 0;j < tmp.size();j++){
				for(int k = j+1;k < tmp.size();k++){
					if(find(i,tmp[j])==find(i,tmp[k])) ans2[{tmp[j],tmp[k]}]++, ans2[{tmp[k],tmp[j]}]++;
				}
			}
			dsu[i].clear();
		}else{
			for(auto [u,v] : color[i]){
				unite(i,u,v);
				adj[u].insert(i);
				adj[v].insert(i);
			}
		}
	}
	int q;
	cin >> q;
	while(q--){
		int u,v;
		cin >> u >> v;
		if(adj[u].size() > adj[v].size()) swap(u,v);
		if(ans.count({u,v})){
			cout << ans[{u,v}]+ans2[{u,v}] << "\n";
			continue;
		}
		int tmp = 0;
		for(auto c : adj[u]){
			tmp += (find(c,u)==find(c,v));
		}
		ans[{u,v}] = tmp;
		cout << tmp+ans2[{u,v}] << "\n";	
	}
}