#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;

struct SegT{
	int node[4*N];

	void modify(int pos, int val, int ind = 1, int l = 0, int r = N-1){
		if(l==r){
			node[ind] = val;
		}else{
			int mid = (l+r)/2;
			if(pos<=mid) modify(pos,val,ind<<1,l,mid);
			else modify(pos,val,ind<<1|1,mid+1,r);
			node[ind] = max(node[ind<<1],node[ind<<1|1]);
		}
	}

	int range_query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
		if(ql>r||qr<l) return INT_MIN;
		if(ql<=l&&qr>=r) return node[ind];
		int mid = (l+r)/2;
		return max(range_query(ql,qr,ind<<1,l,mid),range_query(ql,qr,ind<<1|1,mid+1,r));
	}
} st;

void solve(){
	int n;
	cin >> n;
	int h[n], a[n];
	for(auto &x : h) cin >> x;
	for(auto &x : a) cin >> x;
	for(int i = 0;i < n;i++){
		//cout << i << " " << h[i] << " " << st.range_query(0,h[i]) << " " << a[i] << "\n";
		st.modify(h[i],st.range_query(0,h[i]) + a[i]);
	}
	cout << st.range_query(0,N-1) << "\n"; 
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}