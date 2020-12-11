#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5, MOD = 1e9+7;
vector<int> adj[N];
int dfn[N], low[N], inst[N], scc[N], cnt2[N],sccid = 1, cnt = 0;

int vis[N];
vector<int> adj2[N];
stack<int> st;

void dfs(int u){
	dfn[u] = low[u] = ++cnt;
	st.push(u);
	inst[u] = 1;
	for(auto v : adj[u]){
		if(!dfn[v]){
			dfs(v);
			low[u] = min(low[u],low[v]);
		}else if(inst[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		int x, tmp = 0;
		do{
			x = st.top();
			st.pop();
			scc[x] = sccid;
			inst[x] = 0;
		}while(x!=u);
		sccid++;
	}
}

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res*n%MOD;
		n = n*n%MOD;
		p>>=1;
	}
	return res;
}

int dfs2(int u){
	vis[u] = 1;
	int sz = 1;
	for(auto v : adj2[u]){
		if(!vis[v]) sz += dfs2(v);
	}
	return sz;
}

signed main(){
	fastio
	int n;
	cin >> n;
	vector<pair<int,int>> edges;
	for(int i = 1;i <= n;i++){
		int v;
		cin >> v;
		adj[i].push_back(v);
		edges.push_back({i,v});
	}
	for(int i = 1;i <= n;i++)
		if(!dfn[i]) dfs(i);
	for(auto e : edges){	
		if(scc[e.first]==scc[e.second]) cnt2[scc[e.first]]++;
		else{
			adj2[scc[e.first]].push_back(scc[e.second]);
			adj2[scc[e.second]].push_back(scc[e.first]);
		}
	}
	int ans = 1;
	for(int i = 1;i < sccid;i++){
		if(cnt2[i]>1) ans = ans*(fastpow(2,cnt2[i])-2)%MOD;
	}
	for(int i = 1;i < sccid;i++){
		if(vis[i]) continue;
		int sz = dfs2(i);
		ans = ans*fastpow(2,sz-1)%MOD;
	}
	//ans = ans*fastpow(2,sccid-2);
	cout << ans << "\n";
}