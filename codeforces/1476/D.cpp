#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
int dsu[N], sz[N];

int find(int u){
	return dsu[u] == u ? u : dsu[u] = find(dsu[u]);
}

void unite(int u, int v){
	u = find(u), v = find(v);
	if(u==v) return;
	if(sz[u] > sz[v]) swap(u,v);
	dsu[u] = v;
	sz[v] += sz[u];
}

void solve(){
	int n;
	cin >> n;
	iota(dsu,dsu+2*n+5,0);
	fill(sz,sz+2*n+5,1);
	string s;
	cin >> s;
	for(int i = 0;i < n;i++){
		if(s[i]=='R'){
			unite(i,i+1+(n+1));
		}
		else{
			unite(i+(n+1),i+1);
		}
	}
	for(int i = 0;i <= n;i++) cout << sz[find(i)] << " ";
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}