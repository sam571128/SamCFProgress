#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int arr[N];

struct segT{
	pair<int,int> d[4*N];
	pair<int,int> combine(pair<int,int> a, pair<int,int> b){
		return {max(a.first,b.first),min(a.second,b.second)};
	}
	void build(int a[], int ind = 1, int l = 0, int r = N-1){
		if(l==r){
			d[ind]={a[l],a[l]};
		}else{
			int mid = (l+r)/2;
			build(a,ind<<1,l,mid);
			build(a,ind<<1|1,mid+1,r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		}
	}
	void modify(int pos, int val, int ind = 1, int l = 0, int r = N-1){
		if(l==r){
			d[ind] = {val,val};
		}else{
			int mid = (l+r)/2;
			if(pos<=mid) modify(pos,val,ind<<1,l,mid);
			else modify(pos,val,ind<<1|1,mid+1,r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		}
	}
	pair<int,int> query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
		if(ql>r||qr<l) return {INT_MIN,INT_MAX};
		if(ql<=l&&qr>=r) return d[ind];
		int mid = (l+r)/2;
		return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
	}
} st;

void solve(){
	memset(st.d,0,sizeof st.d);
	int n,m;
	cin >> n >> m;
	int now = 0;
	for(int i = 1; i <= n;i++){
		char c;
		cin >> c;
		if(c=='+') now++;
		else now--;
		arr[i] = now;
		st.modify(i,now,1,1,n);
	}

	while(m--){
		int l,r;
		cin >> l >> r;
		auto [a,b] = st.query(1,l-1,1,1,n);
		a = max(a,0LL), b = min(b,0LL);
		auto [c,d] = st.query(r+1,n,1,1,n);
		if(c < d) cout << a-b+1 << "\n";
		else{
			c -= arr[r]-arr[l-1];
			d -= arr[r]-arr[l-1];
			if(b > d) swap(a,c), swap(b,d);
			if(a >= d&&a<=c) cout << c-b+1 << "\n";
			else if(a <= d) cout << a-b+c-d+2 << "\n";
			else if(a >= c) cout << a-b+1 << "\n";
		}
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}