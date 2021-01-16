#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;

struct segT{
	int d[4*N];
	int combine(int a, int b){
		return max(a,b);
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
	int query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
		if(ql>r||qr<l) return 0;
		if(ql<=l&&qr>=r) return d[ind];
		int mid = (l+r)/2;
		return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
	}
} st;

signed main(){
	fastio
	int n;
	cin >> n;
	int a[n], b[n];
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	st.build(b,1,0,n-1);
	int mx = 0, idx = -1;
	int ans[n] = {};
	for(int i = 0;i < n;i++){
		if(a[i] > mx){
			mx = max(mx,a[i]);
			idx = i;
		}
		//cout << i << " " << mx << " " << st.query(idx,i,1,0,n-1) << "\n";
		//cout << st.query
		ans[i] = max(ans[i],mx*st.query(idx,i,1,0,n-1));
	}
	for(int i = 1;i < n;i++){
		ans[i] = max(ans[i],ans[i-1]);
	}
	for(auto x : ans) cout << x << "\n";
}