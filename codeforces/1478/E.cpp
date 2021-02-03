#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>

//#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
 
int d[4*N];
int lazy_tag[4*N];
int combine(int a, int b){
	return a+b;
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
		lazy_tag[ind] = val;
		d[ind] = (r-l+1)*val;
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
	if(lazy_tag[ind]>=0){
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
	if(lazy_tag[ind]>=0){
		apply(ind<<1, lazy_tag[ind], l, mid);
		apply(ind<<1|1, lazy_tag[ind], mid+1, r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		lazy_tag[ind] = -1;
	}
	return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
}

void solve(){
	int n,q;
	cin >> n >> q;
	string a, b;
	cin >> a >> b;
	int arr[n];
	for(int i = 0;i < n;i++) arr[i] = b[i]-'0';
	int l[q], r[q];
	fill(lazy_tag,lazy_tag+4*n,-1);
	build(arr,1,0,n-1);
	for(int i = 0;i < q;i++){
		cin >> l[i] >> r[i];
		l[i]--,r[i]--;
	}
	for(int i = q-1;~i;i--){
		int num1 = query(l[i],r[i],1,0,n-1), num0 = r[i]-l[i]+1-num1;
		//cout << l[i] << " " << r[i] << " " << num1 << " " << num0 << "\n";
		if(num1*2 > r[i]-l[i]+1){
			range_modify(l[i],r[i],1,1,0,n-1);
		}else if(num0*2 > r[i]-l[i]+1){
			range_modify(l[i],r[i],0,1,0,n-1);
		}else{
			cout << "NO\n";
			return;
		}
	}
	for(int i = 0;i < n;i++){
		//cout << query(i,i,1,0,n-1);
		if(a[i]-'0'!=query(i,i,1,0,n-1)){
			cout << "NO\n";
			return;
		}
	}
	//cout << "\n";
	cout << "YES\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}