#pragma optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 3e5+5;

vector<int> adj[N];
int dfn[N], l[N], t;
int lb[N];
int bcc[N], bccid;
stack<int> st;
 
void dfs(int u, int p){
	//find BCC
	dfn[u] = l[u] = t++;
	st.emplace(u);
	for(int v : adj[u]){
		if(v == p) continue;
		if(!dfn[v]){
			dfs(v,u);
			l[u] = min(l[u],l[v]);
		}
		l[u] = min(l[u],dfn[v]);
	}
	if(l[u]==dfn[u]){
		bccid++;
		int tmp, ma = 0, mi = N;
		do{
			tmp = st.top(); st.pop();
			ma = max(ma,tmp);
			mi = min(mi,tmp);
			bcc[tmp] = bccid;
		}while(tmp!=u);
		lb[ma] = max(lb[ma],mi);
	}
	//if(!st.empty()&&st.top()==u) st.pop();
}
 
int d[4*N];
int lazy_tag[4*N];
int combine(int a, int b){
	return a+b;
}
void build(int a[], int ind = 1, int l = 0, int r = N-1){
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
		d[ind] += (r-l+1)*val;
		lazy_tag[ind] += val;
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
	if(lazy_tag[ind]){
		apply(ind<<1, lazy_tag[ind], l, mid);
		apply(ind<<1|1, lazy_tag[ind], mid+1, r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		lazy_tag[ind] = 0;
	}
	range_modify(ml,mr,val,ind<<1,l,mid);
	range_modify(ml,mr,val,ind<<1|1,mid+1,r);
	d[ind] = combine(d[ind<<1],d[ind<<1|1]);
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

signed main(){
	fastio;
	int n,m;
    cin >> n >> m;
    while(m--){
    	int u,v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for(int i = 1; i <= n;i++) if(!dfn[i]) dfs(i,-1);
    int ma = 0;
    for(int i = 1; i <= n;i++){
    	if(lb[i]!=i) ma = max(lb[i],ma);
    	lb[i] = ma+1;
    }
    int q;
    cin >> q;
   	vector<pair<int,int>> Q[N];
   	int ans[q];
   	for(int i = 0; i < q;i++){
   		int l,r;
   		cin >> l >> r;
   		Q[r].push_back({l,i});
   	}
   	for(int i = 1; i <= n; i++){
   		range_modify(lb[i],i,1,1,1,n);
   		for(auto p : Q[i]){
   			ans[p.second] = query(p.first,i,1,1,n);
   		}
   	}
   	for(auto x : ans) cout << x << "\n";
}