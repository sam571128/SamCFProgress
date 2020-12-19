#pragma optimize(3)
#include <bits/stdc++.h>

//#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
struct SegT{
	int d[4*N];
	int lazy_tag[4*N], lazy_add[4*N];
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
	 
	void assign(int ind, int val, int l, int r){
		if(ind>=0&&ind<4*N){
			d[ind] = (r-l+1)*val;
			lazy_tag[ind] = val;
			lazy_add[ind] = 0;
		}
	}
	void add(int ind, int val, int l, int r){
		if(ind>=0&&ind<4*N){
			d[ind] += (r-l+1)*val;
			lazy_add[ind] += val;
		}
	}
	 
	void range_modify(int mode, int ml, int mr, int val, int ind = 1, int l = 0, int r = N-1){
		if(ml>r||mr<l) return;
		if(ml<=l&&mr>=r){
			if(mode==1){
				lazy_tag[ind] = val;
				d[ind] = (r-l+1)*val;
				lazy_add[ind] = 0;
			}else{
				if(lazy_tag[ind]>-1e8){
					lazy_add[ind] += val;
					lazy_tag[ind] += lazy_add[ind];
					d[ind] = lazy_tag[ind]*(r-l+1);
					lazy_add[ind] = 0;
				}else{
					lazy_add[ind] += val;
					d[ind] += (r-l+1)*val;
				}
			}
			return;
		}
		int mid = (l+r)/2;
		if(lazy_tag[ind]>-1e8){
			assign(ind<<1, lazy_tag[ind], l, mid);
			assign(ind<<1|1, lazy_tag[ind], mid+1, r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
			lazy_tag[ind] = -0x3f3f3f3f;
		}
		if(lazy_add[ind]){
			add(ind<<1, lazy_add[ind], l, mid);
			add(ind<<1|1, lazy_add[ind], mid+1, r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
			lazy_add[ind] = 0;
		}
		range_modify(mode,ml,mr,val,ind<<1,l,mid);
		range_modify(mode,ml,mr,val,ind<<1|1,mid+1,r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
	}
	 
	int query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
		if(qr < ql) return 0;
		if(ql>r||qr<l) return 0;
		if(ql<=l&&qr>=r) return d[ind];
		int mid = (l+r)/2;
		if(lazy_tag[ind]>-1e8){
			assign(ind<<1, lazy_tag[ind], l, mid);
			assign(ind<<1|1, lazy_tag[ind], mid+1, r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
			lazy_tag[ind] = -0x3f3f3f3f;
		}
		if(lazy_add[ind]){
			add(ind<<1, lazy_add[ind], l, mid);
			add(ind<<1|1, lazy_add[ind], mid+1, r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
			lazy_add[ind] = 0;
		}
		return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
	}
	SegT(){
		memset(lazy_tag,-0x3f3f3f3f,sizeof lazy_tag);
	}
} st[26];

void solve(){
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	for(int i = 0;i < n;i++){
		st[s[i]-'a'].range_modify(0,i,i,1,1,0,n-1);
	}
	while(q--){
		int l,r,v;
		cin >> l >> r >> v;
		l--,r--;
		vector<pair<int,int>> tmp;
		if(v==1){
			for(int i = 0;i < 26;i++){
				tmp.push_back({i,st[i].query(l,r,1,0,n-1)});
				st[i].range_modify(1,l,r,0,1,0,n-1);
			}
		}else{
			for(int i = 26-1;~i;i--){
				tmp.push_back({i,st[i].query(l,r,1,0,n-1)});
				st[i].range_modify(1,l,r,0,1,0,n-1);
			}
		}
		int now = l;
		for(auto x : tmp){
			st[x.first].range_modify(0,now,now+x.second-1,1,1,0,n-1);
			//cout << "MODIFY " << x.first << " " << now << " " << now+x.second-1 << " " << st[x.first].query(now,now+x.second-1,1,0,n-1)<< "\n";
			now += x.second;
		}
	}
	string ans = "";
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 26;j++){
			if(st[j].query(i,i,1,0,n-1)){
				ans += char(j+'a');
			}
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}