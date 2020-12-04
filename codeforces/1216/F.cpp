#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
struct segT{
	int d[4*N];
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
			d[ind] = min(val,d[ind]);
		}else{
			int mid = (l+r)/2;
			if(pos<=mid) modify(pos,val,ind<<1,l,mid);
			else modify(pos,val,ind<<1|1,mid+1,r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		}
	}
	int query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
		if(ql>r||qr<l) return 1e18;
		if(ql<=l&&qr>=r) return d[ind];
		int mid = (l+r)/2;
		return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
	}
	void init(){
		for(int i = 0;i < 4*N;i++) d[i] = 1e18;
	}
}t1,t2;

signed main(){
	fastio
	t1.init(), t2.init();
	int n,k;
	cin >> n >> k;
	int dp[n][2] = {}; //0 -> not place, 1 -> place
	string s;
	cin >> s;
	s = "$" + s;
	dp[0][0] = 0, dp[0][1] = 0; t2.modify(0,0,1,0,n);
	for(int i = 1;i <= n;i++){
		dp[i][0] = t1.query(max((int)0,i-k),i-1,1,0,n);
		if(s[i]=='1'){
			dp[i][1] = t2.query(max((int)0,i-k-1),i-1,1,0,n) + i;
		}
		else{
			dp[i][1] = min(t1.query(max((int)0,i-k-1),i-1,1,0,n),min(dp[i-1][0],dp[i-1][1])) + i;
		}
		t2.modify(i,dp[i][1],1,0,n);
		t2.modify(i,dp[i][0],1,0,n);
		if(s[i]=='1') t1.modify(i,dp[i][1],1,0,n);
	}
	cout << min(dp[n][0],dp[n][1]) << "\n";
}