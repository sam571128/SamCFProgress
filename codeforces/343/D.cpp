#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
vector<int> adj[N], euler;
int dep[N], in[N], out[N], par[N];
map<pair<int,int>,int> m;

void dfs(int u){
	in[u] = euler.size();
	euler.push_back(u);
	for(int v : adj[u]){
		if(v==par[u]) continue;
		par[v] = u;
		dfs(v);
		euler.push_back(u);
	}
	out[u] = euler.size()-1;
}

int d[4*N];
int lazy_tag[4*N];
int combine(int a, int b){
	return min(a,b);
}
void build(vector<int> a, int ind = 1, int l = 0, int r = N-1){
	if(l==r){
		d[ind]=a[l];
	}else{
		int mid = (l+r)/2;
		build(a,ind<<1,l,mid);
		build(a,ind<<1|1,mid+1,r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
	}
}
void modify(int pos, int val, int ind = 1, int l = 0, int r = N-1){
	if(l==r){
		d[ind] = val;
	}else{
		int mid = (l+r)/2;
		if(pos<=mid) modify(pos,val,ind<<1,l,mid);
		else modify(pos,val,ind<<1|1,mid+1,r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
	}
}
void apply(int ind, int val, int l, int r){
	if(ind>=0&&ind<4*N){
		d[ind] = val;
		lazy_tag[ind] = val;
	}
}

void range_modify(int ml, int mr, int val, int ind = 1, int l = 0, int r = N-1){
	if(ml>r||mr<l) return;
	if(ml<=l&&mr>=r){
		lazy_tag[ind] = val;
		d[ind] = val;
		return;
	}
	int mid = (l+r)/2;
	if(~lazy_tag[ind]){
		apply(ind<<1, lazy_tag[ind], l, mid);
		apply(ind<<1|1, lazy_tag[ind], mid+1, r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		lazy_tag[ind] = -1;
	}
	range_modify(ml,mr,val,ind<<1,l,mid);
	range_modify(ml,mr,val,ind<<1|1,mid+1,r);
	d[ind] = combine(d[ind<<1],d[ind<<1|1]);
}

int query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
	if(ql>r||qr<l) return 1;
	if(ql<=l&&qr>=r) return d[ind];
	int mid = (l+r)/2;
	if(~lazy_tag[ind]){
		apply(ind<<1, lazy_tag[ind], l, mid);
		apply(ind<<1|1, lazy_tag[ind], mid+1, r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		lazy_tag[ind] = -1;
	}
	return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
}
vector<pair<int,int>> edges;

signed main(){
	fastio
	fill(lazy_tag,lazy_tag+N,-1);
	int n;
	cin >> n;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u,v});
	}
	dfs(1);
	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		if(a==1){
			if(!query(in[b],out[b],1,0,euler.size()-1)&&par[b]) range_modify(in[par[b]],in[par[b]],0,1,0,euler.size()-1);
			range_modify(in[b],out[b],1,1,0,euler.size()-1);
		}else if(a==2){
			range_modify(in[b],in[b],0,1,0,euler.size()-1);
		}else{
			cout << (query(in[b],out[b],1,0,euler.size()-1)) << "\n";
		}
	}
}