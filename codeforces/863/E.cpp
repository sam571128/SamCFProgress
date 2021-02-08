#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

const int N = 1.5e6;
int d[4*N];
int lazy_tag[4*N];
int combine(int a, int b){
	return min(a,b);
}

void apply(int ind, int val, int l, int r){
	if(ind>=0&&ind<4*N){
		d[ind] += val;
		lazy_tag[ind] += val;
	}
}

void range_modify(int ml, int mr, int val, int ind = 1, int l = 0, int r = N-1){
	if(ml>r||mr<l) return;
	int mid = (l+r)/2;
	if(lazy_tag[ind]){
		apply(ind<<1, lazy_tag[ind], l, mid);
		apply(ind<<1|1, lazy_tag[ind], mid+1, r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		lazy_tag[ind] = 0;
	}
	if(ml<=l&&mr>=r){
		lazy_tag[ind] += val;
		d[ind] += val;
		return;
	}
	range_modify(ml,mr,val,ind<<1,l,mid);
	range_modify(ml,mr,val,ind<<1|1,mid+1,r);
	d[ind] = combine(d[ind<<1],d[ind<<1|1]);
}

int query(int ql, int qr, int ind = 1, int l = 0, int r = N-1){
	if(ql>r||qr<l) return INT_MAX;
	if(ql<=l&&qr>=r) return d[ind];
	int mid = (l+r)/2;
	if(lazy_tag[ind]){
		apply(ind<<1, lazy_tag[ind], l, mid);
		apply(ind<<1|1, lazy_tag[ind], mid+1, r);
		d[ind] = combine(d[ind<<1],d[ind<<1|1]);
		lazy_tag[ind] = 0;
	}
	return combine(query(ql,qr,ind<<1,l,mid),query(ql,qr,ind<<1|1,mid+1,r));
}

gp_hash_table<int,int> m;

signed main(){
	fastio
	int n;
	cin >> n;
	vector<int> s;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int l,r;
		cin >> l >> r;
		v.push_back({l,r});
		s.push_back(l);
		s.push_back(l-1);
		s.push_back(r);
	}
	sort(s.begin(),s.end());
	s.resize(unique(s.begin(),s.end())-s.begin());
	n = s.size();
	for(int i = 0;i < n;i++){
		m[s[i]] = i;
	}
	for(auto [l,r] : v){
		range_modify(m[l],m[r],1,1,0,n-1);
	}
	for(int i = 0;i < v.size();i++){
		auto [l,r] = v[i];
		range_modify(m[l],m[r],-1,1,0,n-1);
		if(query(m[l],m[r],1,0,n-1)>=1){
			cout << i+1 << "\n";
			return 0;
		}
		range_modify(m[l],m[r],1,1,0,n-1);

	}
	cout << -1 << "\n";
}