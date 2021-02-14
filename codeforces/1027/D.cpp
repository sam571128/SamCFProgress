#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int val[N], dfn[N], low[N], inst[N], scc[N], deg[N], val2[N];
int n, t, ans = 0, sccid;
stack<int> s;

void dfs(int u){
	dfn[u] = low[u] = ++t;
	s.push(u);
	inst[u] = true;
	for(auto v : adj[u]){
		if(!dfn[v]){
			dfs(v);
			low[u] = min(low[u],low[v]);
		}else if(inst[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		++sccid;
		int x;
		do{
			x = s.top(); s.pop();
			scc[x] = sccid;
			val2[sccid] = min(val2[sccid],val[x]);
			inst[x] = false;
		}while(x!=u);
	}
}

vector<pair<int,int>> edges;

signed main(){
	fastio
	cin >> n;
	fill(val2,val2+N,1e18);
	for(int i = 1;i <= n;i++) cin >> val[i];
	for(int i = 1;i <= n;i++){
		int v;
		cin >> v;
		adj[i].push_back(v);
		edges.push_back({i,v});
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i]) dfs(i);
	}
	for(auto [u,v] : edges){
		if(scc[u]!=scc[v]) {
			deg[scc[u]]++;
		}
	}
	for(int i = 1;i <= sccid;i++){
		if(deg[i]==0)
			ans += val2[i];
	}
	cout << ans << "\n";
}