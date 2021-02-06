#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5, M = 1e6+5;
int num[M];
void init(){
	for(int i = 1;i < M;i++){
		for(int j = i;j < M;j+=i){
			num[j]++;
		}
	}
}

struct node{
	int sum = 0, ma = 0;
	node operator + (node b){
		node res;
		res.sum = sum + b.sum;
		res.ma = max(ma,b.ma);
		return res;
	}
} d[N<<2];

void build(int arr[], int idx, int l, int r){
	if(l==r){
		d[idx] = {arr[l-1],arr[l-1]};
	}else{
		int mid = l+r>>1;
		build(arr,idx<<1,l,mid);
		build(arr,idx<<1|1,mid+1,r);
		d[idx] = d[idx<<1] + d[idx<<1|1];
	}
}

void range_modify(int ml, int mr, int idx, int l, int r){
	if(d[idx].ma<=2) return; 
	if(r < ml || l > mr) return;
	if(l==r){
		d[idx].sum = num[d[idx].sum], d[idx].ma = d[idx].sum;
	}
	else{
		int mid = l+r>>1;
		range_modify(ml,mr,idx<<1,l,mid);
		range_modify(ml,mr,idx<<1|1,mid+1,r);
		d[idx] = d[idx<<1] + d[idx<<1|1];
	}
}

node query(int ql, int qr, int idx, int l, int r){
	if(l >= ql && r <= qr) return d[idx];
	int mid = l+r>>1;
	node res = {0,0};
	if(qr <= mid) return query(ql,qr,idx<<1,l,mid);
	else if(ql > mid) return query(ql,qr,idx<<1|1,mid+1,r);
	else return query(ql,qr,idx<<1,l,mid) + query(ql,qr,idx<<1|1,mid+1,r);
}

signed main(){
	fastio
	init();
	int n,q;
	cin >> n >> q;
	int arr[n];
	for(auto &x : arr) cin >> x;
	build(arr,1,1,n);
	while(q--){
		int a;
		cin >> a;
		if(a==2){
			int l,r;
			cin >> l >> r;
			cout << query(l,r,1,1,n).sum << "\n";
		}else if(a==1){
			int l,r,x;
			cin >> l >> r;
			range_modify(l,r,1,1,n);
		}
	}
}