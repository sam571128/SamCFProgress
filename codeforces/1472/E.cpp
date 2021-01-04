#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n],b[n];
	vector<pair<int,pair<int,int>>> v;
	int val = INT_MAX, idx = -1;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		a[i] = x, b[i] = y;
		v.push_back({i,{x,y}});
		v.push_back({i,{y,x}});
	}
	sort(v.begin(),v.end(),[&](pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
		return a.second.first==b.second.first ? a.second.second > b.second.second : a.second.first < b.second.first;
	});
	int ans[n];
	for(int i = 0;i < v.size();i++){
		if(a[v[i].first]==v[i].second.first&&b[v[i].first]==v[i].second.second){
		//cout << val << " " << idx << " " << i << " " << v[i].first << " " << v[i].second.first << " " << v[i].second.second << "\n";
			if(val < v[i].second.second) ans[v[i].first] = idx;
			else ans[v[i].first] = -1;
		}
		if(val > v[i].second.second) val = v[i].second.second, idx = v[i].first+1;
	}
	for(auto &x : ans) cout << x << " ";
	cout << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}