#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5,MOD = 998244353;

int d[4*N];
int lazy_tag[4*N];
int combine(int a, int b){
	return (a+b)%MOD;
}

void modify(int pos, int val, int ind = 1, int l = 0, int r = N-1){
	if(l==r){
		d[ind] = val%MOD;
	}else{
		int mid = (l+r)/2;
		if(pos<=mid) modify(pos,val,ind<<1,l,mid);
		else modify(pos,val,ind<<1|1,mid+1,r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
	}
}

void apply(int ind, int val, int l, int r){
	if(ind>=0&&ind<4*N){
		d[ind] = (d[ind] + (r-l+1)*val%MOD)%MOD;
		lazy_tag[ind] = (lazy_tag[ind] + val%MOD)%MOD;
	}
}

void range_modify(int ml, int mr, int val, int ind = 1, int l = 0, int r = N-1){
	if(ml>r||mr<l) return;
	if(ml<=l&&mr>=r){
		d[ind] = (d[ind] + (r-l+1)*val%MOD)%MOD;
		lazy_tag[ind] = (lazy_tag[ind] + val%MOD)%MOD;
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
	if(ql<=l&&qr>=r) return d[ind]%MOD;
	int mid = (l+r)/2;
	if(lazy_tag[ind]){
		apply(ind<<1, lazy_tag[ind], l, mid);
		apply(ind<<1|1, lazy_tag[ind], mid+1, r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		lazy_tag[ind] = 0;
	}
	return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
}

vector<pair<int,int>> v;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	while(k--){
		int l,r;
		cin >> l >> r;
		v.push_back({l,r});
	}
	int arr[n+1] = {};
	range_modify(1,1,1,1,1,n);
	for(int i = 1;i < n;i++){
		arr[i] = query(i,i,1,1,n);
		for(auto x : v){
			if(x.first+i>n) continue;
			range_modify(x.first+i,min(n,x.second+i),arr[i],1,1,n);
		}
	}
	cout << query(n,n,1,1,n) << "\n";
}