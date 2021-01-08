#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int dsu[N], nxt[N];

int find(int u){
	return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}

void unite(int u, int v){
	u = find(u), v = find(v);
	if(u==v) return;
	if(u > v) swap(u,v);
	dsu[u] = v;
}

signed main(){
	fastio
	iota(dsu,dsu+N,0);
	iota(nxt,nxt+N,1);
	int n,q;
	cin >> n >> q;
	while(q--){
		int a,b,c;
		cin >> a >> b >> c;
		if(a==1){
			unite(b,c);
		}else if(a==2){
			int now = 0;
			for(int i = b+1;i <= c;i=now){
				unite(i-1,i);
				now = nxt[i];
				nxt[i] = c+1;
			}
		}else{
			b = find(b), c = find(c);
			cout << (b==c ? "YES\n" : "NO\n");
		}
	}
}