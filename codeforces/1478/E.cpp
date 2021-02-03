#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;

struct SegT{
	int d[4*N];
	int lazy_tag[4*N];
	int combine(int a, int b){
		return a+b;
	}
	void build(string &s, int ind = 1, int l = 0, int r = N-1){
		lazy_tag[ind] = -1;
		if(l==r){
			d[ind]=s[l]-'0';
		}else{
			int mid = (l+r)/2;
			build(s,ind<<1,l,mid);
			build(s,ind<<1|1,mid+1,r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		}
	}

	void apply(int ind, int val, int l, int r){
		if(ind>=0&&ind<4*N){
			d[ind] = (r-l+1)*val;
			lazy_tag[ind] = val;
		}
	}

	void range_modify(int ml, int mr, int val, int ind = 1, int l = 0, int r = N-1){
		if(ml>r||mr<l) return;
		if(ml<=l&&mr>=r){
			lazy_tag[ind] = val;
			d[ind] = (r-l+1)*val;
			return;
		}
		int mid = (l+r)/2;
		if(lazy_tag[ind] >= 0){
			apply(ind<<1, lazy_tag[ind], l, mid);
			apply(ind<<1|1, lazy_tag[ind], mid+1, r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
			lazy_tag[ind] = -1;
		}
		range_modify(ml,mr,val,ind<<1,l,mid);
		range_modify(ml,mr,val,ind<<1|1,mid+1,r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
	}
	
	int query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
		if(ql>r||qr<l) return 0;
		if(ql<=l&&qr>=r) return d[ind];
		int mid = (l+r)/2;
		if(lazy_tag[ind] >= 0){
			apply(ind<<1, lazy_tag[ind], l, mid);
			apply(ind<<1|1, lazy_tag[ind], mid+1, r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
			lazy_tag[ind] = -1;
		}
		return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
	}
} st;

void solve(){
	int n,q;
	cin >> n >> q;
	string a, b;
	cin >> a >> b;
	st.build(b,1,0,n-1);
	vector<pair<int,int>> v;
	while(q--){
		int l,r;
		cin >> l >> r;
		l--,r--;
		v.push_back({l,r});
	}
	reverse(v.begin(),v.end());
	for(auto [l,r] : v){
		int num1 = st.query(l,r,1,0,n-1), num0 = r-l+1-num1;
		if(num1*2 > r-l+1){
			st.range_modify(l,r,1,1,0,n-1);
		}else if(num0*2 > r-l+1){
			st.range_modify(l,r,0,1,0,n-1);
		}else{
			cout << "NO\n";
			return;
		}
	}
	for(int i = 0;i < n;i++){
		if(a[i]-'0'!=st.query(i,i,1,0,n-1)){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}