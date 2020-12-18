#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

const int N = 1e5+5;
int dsu[N];
gp_hash_table<int,int> edge[N];
set<int> s[N];

int find(int u){
	return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}

void unite(int u, int v){
	u = find(u), v = find(v);
	if(u==v) return;
	if(s[u].size() > s[v].size()) swap(u,v);
	dsu[u] = v;
	for(auto x : s[u]) s[v].insert(x);
	s[u].clear();
}

void add(int u, int v, int col){
	if(edge[u][col]){
		unite(edge[u][col],v);
	}else{
		edge[u][col] = v;
	}
	if(edge[v][col]){
		unite(u,edge[v][col]);
	}else{
		edge[v][col] = u;
	}
	s[find(u)].insert(v);
	s[find(v)].insert(u);
}

signed main(){
	fastio
	iota(dsu,dsu+N,0);
	int n,m,c,q;
	cin >> n >> m >> c >> q;
	for(int i = 0;i < m;i++){
		int u,v,col;
		cin >> u >> v >> col;
		add(u,v,col);
	}
	for(int i = 0;i < q;i++){
		char ch;
		cin >> ch;
		if(ch=='?'){
			int u,v;
			cin >> u >> v;
			if(find(u)==find(v)||s[find(u)].find(v)!=s[find(u)].end()){
				cout << "Yes\n";
			}else{
				cout << "No\n";
			}
		}else{
			int u,v,col;
			cin >> u >> v >> col;
			add(u,v,col);
		}
	}
}