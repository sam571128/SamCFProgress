#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1<<18;
struct segT{
	int data[4*N], swp[20];
	void modify(int pos, int val, int l, int r, int ind = 1, int dep = 0){
		if(l==r){
			data[ind] = val;
		}else{
			int mid = l+r>>1;
			if(swp[dep]){
				if(pos <= mid) modify(pos,val,l,mid,ind<<1|1,dep+1);
				else modify(pos,val,mid+1,r,ind<<1,dep+1);
				data[ind] = data[ind<<1] + data[ind<<1|1];
			}else{
				if(pos <= mid) modify(pos,val,l,mid,ind<<1,dep+1);
				else modify(pos,val,mid+1,r,ind<<1|1,dep+1);
				data[ind] = data[ind<<1] + data[ind<<1|1];
			}
		}
	}
	int query(int ql, int qr, int l, int r, int ind = 1, int dep = 0){
		if(ql > r || qr < l) return 0;
		if(ql <= l && qr >= r) return data[ind];
		int mid = l+r>>1;
		if(swp[dep]){
			return query(ql,qr,l,mid,ind<<1|1,dep+1) + query(ql, qr, mid + 1, r, ind<<1, dep+1);
		}else{
			return query(ql,qr,l,mid,ind<<1,dep+1) + query(ql, qr, mid + 1, r, ind<<1|1, dep+1);
		}
	}
} st;

signed main(){
	fastio
	int n, q;
	cin >> n >> q;
	for(int i = 1, tmp;i <= 1<<n;i++){
		cin >> tmp;
		st.modify(i,tmp,1,1<<n);
	}
	while(q--){
		int t;
		cin >> t;
		if(t==1){
			int x, k;
			cin >> x >> k;
			st.modify(x,k,1,1<<n);
		}else if(t==2){
			int k;
			cin >> k;
			for(int i = n-k;i < n;i++){
				st.swp[i] ^= 1;
			}
		}else if(t==3){
			int k;
			cin >> k;
			st.swp[n-k-1] ^= 1;
		}else{
			int l, r;
			cin >> l >> r;
			cout << st.query(l,r,1,1<<n) << "\n";
		}
	}

}