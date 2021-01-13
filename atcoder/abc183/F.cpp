#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int dsu[N];
map<int,int> g[N];

int find(int u){
	return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}

void unite(int u, int v){
	u = find(u), v = find(v);
	if(u==v) return;
	if(g[u].size() > g[v].size()) swap(u,v);
	for(auto [a,b] : g[u]){
		g[v][a] += b;
	}
	g[u].clear();
	dsu[u] = v;
}

signed main(){
	fastio
	iota(dsu,dsu+N,0);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		int tmp;
		cin >> tmp;
		g[i][tmp]++;
	}
	while(q--){
		int a,x,y;
		cin >> a >> x >> y;
		if(a==1) unite(x,y);
		else{
			x = find(x);
			cout << g[x][y] << "\n";
		}
	}
}