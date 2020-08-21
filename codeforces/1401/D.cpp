#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>
#include <bits/extc++.h>


using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(x,m,n) for(int x = m; x < n;x++)
#define repp(x,m,n) for(int x = m; x <= n;x++)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update, ordered_set>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//find_by_order(), order_of_key();
#define MOD 1000000007

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int n;
vector<int> vt;

int dfs(int u){
	visited[u] = true;
	int cnt = 1;
	for(auto v : adj[u]){
		if(visited[v]) continue;
		int tt = dfs(v);
		cnt += tt;
		vt.emplace_back(tt*(n-tt));
	}
	return cnt;
}

void solve(){
	cin >> n;
	for(int i = 0;i <= n;i++){
		adj[i].clear();
		visited[i] = false;
	}
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	sort(vt.begin(),vt.end());
	int m;
	cin >> m;
	vector<int> tt;
	for(int i = 0, tmp;i < m;i++) cin >> tmp, tt.push_back(tmp);
	sort(tt.begin(),tt.end());
	int ans = 0;
	while(tt.size()>vt.size()){
		int ok = tt[tt.size()-1]*tt[tt.size()-2]%MOD; tt.pop_back(), tt.pop_back();
		tt.push_back(ok);
	}
	while(!tt.empty()){
		//cout << tt.back() << " " << vt.back() << " " << tt.back()*vt.back() << "\n";
		ans = (ans + tt.back()*vt.back())%MOD; tt.pop_back(); vt.pop_back();
	} 
	while(!vt.empty()){
		//cout << vt.back() << "\n";
		ans = (ans + vt.back())%MOD; vt.pop_back();
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	rep(i,0,t) solve();
}

