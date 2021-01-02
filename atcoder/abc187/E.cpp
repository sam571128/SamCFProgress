#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
vector<int> adj[N], euler;
int dep[N], idx[N];
map<pair<int,int>,int> m;

void dfs(int u, int par){
	idx[u] = euler.size();
	euler.push_back(u);
	for(int v : adj[u]){
		if(v==par) continue;
		m[{u,v}] = euler.size();
		dfs(v,u);
		m[{v,u}] = euler.size();
		euler.push_back(u);
	}
	
}

int d[4*N];
int lazy_tag[4*N];
int combine(int a, int b){
	return a+b;
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
void range_modify(int ml, int mr, int val, int ind = 1, int l = 0, int r = N-1){
	if(ml>r||mr<l) return;
	if(ml<=l&&mr>=r){
		lazy_tag[ind] += val;
		d[ind] += (r-l+1)*val;
		return;
	}
	int mid = (l+r)/2;
	range_modify(ml,mr,val,ind<<1,l,mid);
	range_modify(ml,mr,val,ind<<1|1,mid+1,r);
	d[ind] = combine(d[ind<<1],d[ind<<1|1]);
}
void apply(int ind, int val, int l, int r){
	if(ind>=0&&ind<4*N){
		d[ind] += (r-l+1)*val;
		lazy_tag[ind] += val;
	}
}
int query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
	if(ql>r||qr<l) return 0;
	if(ql<=l&&qr>=r) return d[ind];
	int mid = (l+r)/2;
	if(lazy_tag[ind]){
		apply(ind<<1, lazy_tag[ind], l, mid);
		apply(ind<<1|1, lazy_tag[ind], mid+1, r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		lazy_tag[ind] = 0;
	}
	return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
}
vector<pair<int,int>> edges;

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u,v});
	}
	dfs(1,1);
	//for(auto x : euler) cout << x << " ";
	//cout << "\n";
	int q;
	cin >> q;
	while(q--){
		int t,e,val;
		cin >> t >> e >> val;
		auto [u,v] = edges[e-1];
		if(t==2) swap(u,v);
		if(m[{u,v}] > m[{v,u}]){
			range_modify(m[{v,u}]+1,m[{u,v}],val,1,1,euler.size());
			//cout << u << " " << v << " " << m[{v,u}]+1 << " " << m[{u,v}] << " " << val << "\n";
		}else{
			range_modify(1,m[{u,v}],val,1,1,euler.size());
			range_modify(m[{v,u}]+1,euler.size(),val,1,1,euler.size());
			//cout << 1 << " " << m[{u,v}] << " " << val << "\n";
			//cout << m[{v,u}]+1 << " " << euler.size() << " " << val << "\n";
		}
	}
	for(int i = 1;i <= n;i++){
		//cout << idx[i]+1 << "\n";
		cout << query(idx[i]+1,idx[i]+1,1,1,euler.size()) << "\n";
	}
}