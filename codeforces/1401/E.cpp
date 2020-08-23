#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;

struct BIT{
	int data[N];
	void modify(int pos, int val){
		while(pos < N){
			data[pos] += val;
			pos += pos & (-pos);
		}
	}
	int sum(int pos){
		int res = 0;
		for(;pos>0;pos-=pos&(-pos)){
			res += data[pos];
		}
		return res;
	}
	int query(int l, int r){
		return sum(r) - sum(max((int)0,l-1));
	}
} bit;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int ans = 1;
	vector<array<int,3>> v;
	for(int i = 0;i < n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(c-b==(int)1e6) ans++;
		v.push_back({b,a,1});
		v.push_back({c+1,a,-1});
	}
	for(int i = 0;i < m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(c-b==(int)1e6) ans++;
		v.push_back({a,b,c+2});
	}
	sort(v.begin(),v.end(), [&](array<int,3> a, array<int,3> b){
		if(a[0] != b[0]) return a[0] < b[0];
		return a[2] < b[2];
	});
	bool checked = false;
	
	for(auto x : v){
		if(x[2] > 1){
			//cout << x[0] << " " << bit.query(x[1],x[2]-2) << "\n" ;
			ans += bit.query(x[1],x[2]-2);
		}else{
			bit.modify(x[1],x[2]);
		}
	}
	cout << ans << "\n";
}
/*
3 3
2 3 1000000
4 0 3
3 0 1000000
4 0 1
2 0 5
3 1 1000000*/