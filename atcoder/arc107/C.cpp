#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 55, MOD = 998244353;
int dsu[N], sz[N];

int find(int u){
	return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}

void unite(int u, int v){
	u = find(u), v = find(v);
	if(u==v) return;
	if(sz[u] > sz[v]) swap(u,v);
	dsu[u] = v;
	sz[v] += sz[u];
}

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	iota(dsu,dsu+N,0);
	fill(sz,sz+N,1);
	int arr[n][n];
	for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> arr[i][j];
	int ans = 1;
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			bool ok = true;
			for(int l = 0;l < n;l++){
				if(arr[i][l]+arr[j][l] > k) ok = false;
			}
			if(ok){
				unite(i,j);
			}
		}
	}
	for(int i = 0;i < n;i++) if(dsu[i] == i) for(int j = 1;j <= sz[i];j++) ans = ans*j%MOD;
	iota(dsu,dsu+N,0);
	fill(sz,sz+N,1);
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			bool ok = true;
			for(int l = 0;l < n;l++){
				if(arr[l][i]+arr[l][j] > k) ok = false;
			}
			if(ok) unite(i,j);
		}
	}
	for(int i = 0;i < n;i++) if(dsu[i] == i) for(int j = 1;j <= sz[i];j++) ans = ans*j%MOD;
	cout << ans << "\n";
}