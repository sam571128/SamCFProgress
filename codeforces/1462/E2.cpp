#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5, MOD = 1e9+7;
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

int fact[N];

void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++)
		fact[i] = fact[i-1]*i%MOD;
}

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

int nCr(int n, int r){
	if(n < r) return 0;
	return fact[n]*fastpow(fact[n-r],MOD-2)%MOD*fastpow(fact[r],MOD-2)%MOD;
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	st.build(arr,1,0,n-1);
	int l = 0, r = -1, ans = 0;
	while(l < n){
		while(r+1 < n && st.query(l,r+1,1,0,n-1).diff <= k){
			r++;
		}
		ans = (ans+nCr(r-l,m-1))%MOD;
		l++;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	init();
	int t = 1;
	cin >> t;
	while(t--) solve();
}