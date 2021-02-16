#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int,vector<int>> m;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		m[tmp].push_back(i+1);
	}
	int sum[m.size()];
	vector<int> v;
	int now = 0, cnt = 0;
	for(auto [a,b] : m){
		v.push_back(a);
		now += a*b.size();
		sum[cnt] = now;
		cnt++;
	}
	vector<int> ans{v.back()};
	int sz = m[v.back()].size();
	for(int i = v.size()-1;i;i--){
		if(sum[i-1] >= v[i]){
			sz += m[v[i-1]].size();
			ans.push_back(v[i-1]);
		}else break;
	}
	vector<int> anss;
	cout << sz << "\n";
	for(auto x : ans){
		for(auto y : m[x]){
			anss.push_back(y);
		}
	}
	sort(anss.begin(),anss.end());
	for(auto x : anss) cout << x << " ";
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}