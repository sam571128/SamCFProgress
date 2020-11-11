#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 1e5+5;

int t,dsu[N],color[N],sz[N],mx[N],ans[N];
map<int,int>cnt[N];
vector<int> adj[N];

void relax(int s,int x,int u){
	if(x>mx[s])mx[s]=x,ans[s]=u;
	else if(x==mx[s])ans[s]+=u;
}
void merge(int s,int u,int v){
	for(auto [a,b] :cnt[v])
		relax(s,cnt[u][a]+=b,a);
}
void dfs(int u,int par){
	sz[u]=1;
	if(!adj[u].size() || adj[u].size()==1 && adj[u].back()==par){
		dsu[u]=t;
		cnt[t++][color[u]]=1;
		ans[u]=color[u];
		mx[u]=1;
		return;
	}
	int heavy=N-1;
	for(auto &v:adj[u]) if(v!=par){
	  dfs(v,u);
	  sz[u]+=sz[v];
	  if(sz[heavy]<sz[v]) heavy = v;
	}
	dsu[u]=dsu[heavy];
	ans[u]=ans[heavy];
	mx[u]=mx[heavy];
	for(auto &v:adj[u]){
		if(v!=par && v!=heavy) merge(u,dsu[u],dsu[v]);
	}
	relax(u,++cnt[dsu[u]][color[u]],color[u]);
}
signed main(){
	fastio
	int n;
	cin >> n;
  	for(int i = 1;i <= n;i++) cin >> color[i];
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,1);
	for(int i = 1;i <= n;i++) cout << ans[i] << " " ;
}