#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;

struct SegT{
	int d[4*N];
	int lazy_tag[4*N];
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
		if(d[ind] < 0) return -1;
		if(l==r) return d[ind] ? -1 : l+1;
		int mid = l+r>>1;
		if(lazy_tag[ind]){
			apply(ind<<1, lazy_tag[ind], l, mid);
			apply(ind<<1|1, lazy_tag[ind], mid+1, r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
			lazy_tag[ind] = 0;
		}
		int tmp = query(ind<<1,l,mid);
		if(tmp > 0) return tmp;
		else return query(ind<<1|1,mid+1,r);
	}
} st;

signed main(){
	fastio
	int n,q;
	cin >> n >> q;
	int arr[n], pref[n+1] = {}, arr2[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		pref[i+1] = pref[i]+arr[i];
		arr2[i] = arr[i]-pref[i];
	}
	st.build(arr2,1,0,n-1);
	while(q--){
		int p,x;
		cin >> p >> x;
		p--;
		int tmp = x; x = x - arr[p]; arr[p] = tmp; 
		st.range_modify(p,p,x,1,0,n-1);
		st.range_modify(p+1,n-1,-x,1,0,n-1);
		cout << st.query(1,0,n-1) << "\n";
	}
}