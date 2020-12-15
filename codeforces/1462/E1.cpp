#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
struct segT{
	struct node{
		int mi = 1e18, ma = 0, diff = abs(mi-ma);
	};
	node d[4*N];
	node combine(node a, node b){
		node c;
		c.mi = min(a.mi,b.mi);
		c.ma = max(a.ma,b.ma);
		c.diff = abs(c.mi-c.ma);
		return c; 
	}
	void build(int a[], int ind = 1, int l = 0, int r = N-1){
		if(l==r){
			d[ind].mi = d[ind].ma = a[l], d[ind].diff = 0;
		}else{
			int mid = (l+r)/2;
			build(a,ind<<1,l,mid);
			build(a,ind<<1|1,mid+1,r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		}
	}
	node query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
		if(ql>r||qr<l) return {(int)1e18,0,0};
		if(ql<=l&&qr>=r) return d[ind];
		int mid = (l+r)/2;
		return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
	}
} st;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	st.build(arr,1,0,n-1);
	int l = 0, r = -1, ans = 0;
	while(l < n){
		while(r+1 < n && st.query(l,r+1,1,0,n-1).diff <= 2){
			r++;
		}
		if(r!=-1)ans += (r-l)*(r-l-1)/2;
		l++;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}