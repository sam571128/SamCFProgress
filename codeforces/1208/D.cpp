#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
struct SegT{
	int d[4*N];
	int lazy_tag[4*N];
	int combine(int a, int b){
		return min(a,b);
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
			d[ind] += val;
			lazy_tag[ind] += val;
		}
	}
	void range_modify(int ml, int mr, int val, int ind = 1, int l = 0, int r = N-1){
		if(ml>r||mr<l) return;
		if(ml<=l&&mr>=r){
			lazy_tag[ind] += val;
			d[ind] += val;
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
	int query(int ind = 1, int l = 0, int r = N-1){
		if(l==r) return l;
		int mid = (l+r)/2;
		int idx = -1;
		if(lazy_tag[ind]){
			apply(ind<<1, lazy_tag[ind], l, mid);
			apply(ind<<1|1, lazy_tag[ind], mid+1, r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
			lazy_tag[ind] = 0;
		}
		if(d[ind<<1|1] == 0){
			idx = query(ind<<1|1,mid+1,r);
		}else{
			idx = query(ind<<1,l,mid);
		}
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		return idx;
	}
} st;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	st.build(arr,1,0,n-1);
	int ans[n] = {};
	for(int i = 1;i <= n;i++){
		int idx = st.query(1,0,n-1);
		ans[idx] = i;
		st.range_modify(idx,idx,1e18,1,0,n-1);
		st.range_modify(idx+1,n-1,-i,1,0,n-1);
	}
	for(auto x : ans) cout << x << " ";
}