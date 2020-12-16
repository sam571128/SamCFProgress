#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,d,k;
	cin >> n >> d >> k;

	if(d >= n) {
		cout << "NO\n";
		return 0;
	}
	int deg[n] = {};
	vector<pair<int,int>> ans;
	set<pair<int,int>> s;
	for(int i = 0;i < d;i++){
		//Build 0,1,2,3,...,d-1 as vertex on diameter
		deg[i]++, deg[i+1]++;
		if(deg[i] > k || deg[i+1] > k){
			cout << "NO\n";
			return 0;
		}
		ans.push_back({i,i+1});
	}
	for(int i = 1;i < d;i++){
		//Push the vertex of 1,2...,d-2 into set
		s.insert({max(i,d-i),i});
	}
	for(int i = d+1;i < n;i++){
		while(!s.empty()&&deg[(*s.begin()).second]==k)
			s.erase(s.begin());	
		if(s.empty()){
			cout << "NO\n";
			return 0;
		}
		auto p = *s.begin();
		if(p.first==d){
			cout << "NO\n";
			return 0;
		}
		++deg[p.second]; ++deg[i];
		ans.push_back({p.second,i});
		s.insert({p.first+1,i});
	}
	cout << "YES\n";
	for(auto x : ans) cout << x.first+1 << " " << x.second+1 << "\n";
}