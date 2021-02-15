#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adj[N*10];
int A[4*N], B[4*N], now, num[N], inq[N*10], dis[N*10];

void add_edge(int u, int v, int w){
	adj[u].push_back({v,w});
}

void build(int idx, int l, int r){
	if(l==r){
		A[idx] = B[idx] = now;
		num[l] = now;
		now++;
		return;
	}
	int mid = l+r>>1;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
	A[idx] = now++;
	B[idx] = now++;
	add_edge(A[idx<<1],A[idx],0);
	add_edge(A[idx<<1|1],A[idx],0);
	add_edge(B[idx],B[idx<<1],0);
	add_edge(B[idx],B[idx<<1|1],0);
}

void update1(int v, int ql, int qr, int w, int idx, int l, int r){
	if(ql > r || qr < l) return;
	if(ql <= l && qr >= r){
		add_edge(num[v],B[idx],w);
		return;
	}
	int mid = l+r>>1;
	update1(v,ql,qr,w,idx<<1,l,mid);
	update1(v,ql,qr,w,idx<<1|1,mid+1,r);
}

void update2(int v, int ql, int qr, int w, int idx, int l, int r){
	if(ql > r || qr < l) return;
	if(ql <= l && qr >= r){
		add_edge(A[idx],num[v],w);
		return;
	}
	int mid = l+r>>1;
	update2(v,ql,qr,w,idx<<1,l,mid);
	update2(v,ql,qr,w,idx<<1|1,mid+1,r);
}

signed main(){
	fastio
	int n,q,s;
	cin >> n >> q >> s;
	build(1,1,n);
	fill(dis,dis+now,1e18);
	while(q--){
		int op;
		cin >> op;
		if(op==1){
			int u,v,w;
			cin >> u >> v >> w;
			add_edge(num[u],num[v],w);
		}else if(op==2){
			int u,l,r,w;
			cin >> u >> l >> r >> w;
			update1(u,l,r,w,1,1,n);
		}else if(op==3){
			int v,l,r,w;
			cin >> v >> l >> r >> w;
			update2(v,l,r,w,1,1,n);
		}
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,num[s]});
	dis[num[s]] = 0;
	inq[num[s]] = 1;
	while(!pq.empty()){
		auto [ww,u] = pq.top(); pq.pop();
		inq[u] = 0;
		for(auto [v,w] : adj[u]){
			if(dis[v] > dis[u]+ w){
				dis[v] = dis[u]+w;
				if(!inq[v]){
					pq.push({dis[v],v});
					inq[v] = 1;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(dis[num[i]]==1e18) cout << -1 << " ";
		else cout << dis[num[i]] << " ";
	}
}