#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<int,int> m, m2;

set<int> s;

signed main(){
	fastio
	int n,c;
	cin >> n >> c;
	vector<array<int,3>> v;
	for(int i = 0;i < n;i++){
		int l,r,cc;
		cin >> l >> r >> cc;
		v.push_back({l,r,cc});
		s.insert(l);
		s.insert(r);
		s.insert(r+1);
	}
	s.insert(0);
	int id = 0;
	for(auto x : s){
		m[id] = x;
		m2[x] = id;
		id++;
	}
	m[id] = *s.rbegin()+1;
	int arr[s.size()+1] = {};
	for(auto [l,r,cc] : v){
		arr[m2[l]] += cc;
		arr[m2[r+1]] -= cc;
	}
	int ans = 0, now = 0;
	for(int i = 0;i < s.size();i++){
		now += arr[i];
		if(now >= c){
			ans += c * (m[i+1]-m[i]);
		}
		else{
			ans += now * (m[i+1]-m[i]);
		}
	}
	cout << ans << "\n";

}
/*
5 1000000000
583563238 820642330 1
136809000 653199778 2
54601291 785892285 3
5797762 453599267 4
468677897 916692569 5
*/