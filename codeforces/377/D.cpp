#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5;
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
	int gety(int val, int ind = 1, int l = 0, int r = N-1){
		if(l==r) return l;
		int mid = (l+r)>>1;
		if(lazy_tag[ind]){
			apply(ind<<1, lazy_tag[ind], l, mid);
			apply(ind<<1|1, lazy_tag[ind], mid+1, r);
			d[ind] = combine(d[ind<<1],d[ind<<1|1]);
			lazy_tag[ind] = 0;
		}
		if(d[ind<<1]==val) return gety(val,ind<<1,l,mid);
		else return gety(val,ind<<1|1,mid+1,r);
	}
} st;

struct line{
	int x,y1,y2,val;
	line(int x, int y1, int y2, int val): x(x), y1(y1), y2(y2), val(val){}
	bool operator < (line b){
		return (x == b.x ? val > b.val : x < b.x);
	}
};

signed main(){
	fastio
	int n;
	cin >> n;
	int lb[n], vals[n], rb[n]; 
	vector<line> v;
	for(int i = 0;i < n;i++){
		cin >> lb[i] >> vals[i] >> rb[i];
		v.emplace_back(lb[i],vals[i],rb[i],1);
		v.emplace_back(vals[i],vals[i],rb[i],-1);
	}
	sort(v.begin(),v.end());
	/*for(auto x : v){
		cout << x.x << " " << x.y1 << " " << x.y2 << " " << x.val << "\n";
	}*/
	int ans = 0, x = 0, y = 0;
	for(int i = 0;i < v.size();i++){
		st.range_modify(v[i].y1,v[i].y2,v[i].val);
		int tmp = st.d[1];
		if(ans < tmp) ans = tmp, x = v[i].x, y = st.gety(tmp);
	}
	cout << ans << "\n";
	//cout << x << " " << y << "\n";
	for(int i = 0;i < n;i++){
		if(lb[i] <= x && vals[i] >= x && rb[i] >= y && vals[i] <= y){
			cout << i+1 << " ";
		}
	}
}