#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5, INF = 1e18;
struct node{
	int num[10], ans; 
	//to maintain when the ith digit is non-zero what is the smallest value in [l,r]
	node(){
		ans = INF;
		for(auto &x : num) x = INF;
	}
};

node d[4*N];
node combine(node a, node b){
	node c;
	c.ans = min(a.ans,b.ans);
	for(int i = 0;i < 10;i++){
		c.num[i] = min(a.num[i],b.num[i]);
		if(a.num[i] < INF && b.num[i] < INF)
			c.ans = min(c.ans,a.num[i]+b.num[i]);
	}
	return c;
}
void modify(int pos, int val, int ind = 1, int l = 0, int r = N-1){
	if(l==r){
		d[ind] = node();
		int tt = 0;
		int tmp = val;
		while(val!=0){
			if(val%10) d[ind].num[tt] = min(d[ind].num[tt],tmp);
			val/=10;
			tt++;
		}
		return;
	}else{
		int mid = (l+r)/2;
		if(pos<=mid) modify(pos,val,ind<<1,l,mid);
		else modify(pos,val,ind<<1|1,mid+1,r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
	}
}
node query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
	if(ql<=l&&qr>=r) return d[ind];
	int mid = (l+r)/2;
	if(qr <= mid) return query(ql,qr,ind<<1,l,mid);
	if(ql > mid) return query(ql,qr,ind<<1|1,mid+1,r);
	node a = query(ql,mid,ind<<1,l,mid);
	node b = query(mid+1,qr,ind<<1|1,mid+1,r);
	return combine(a,b);
	//return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		modify(i+1,tmp,1,1,n);
	}
	/*node nn = query(2,2,1,1,n);
	for(int i = 0;i < 10;i++){
		cout << nn.num[i] << "\n";
	}*/
	//cout << query(1,1,1,1,n).ans << "\n";
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		if(a==1){
			modify(b,c,1,1,n);
		}else{
			node res = query(b,c,1,1,n);
			cout << (res.ans == INF ? -1 : res.ans) << "\n";
		}
	}
}