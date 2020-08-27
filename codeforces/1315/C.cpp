#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	//Unsolved
	int n;
	cin >> n;
	int a[n];
	set<int> s;
	for(int i = 1;i <= 2*n;i++) s.insert(i);
	for(int i = 0;i < n;i++){
		cin >> a[i]; s.erase(a[i]);
	}
	vector<int> v;
	for(int i = 0;i < n;i++){
		v.push_back(a[i]);
		auto itr = s.lower_bound(a[i]);
		if(itr==s.end()){
			cout << -1 << "\n";
			return;
		}
		v.push_back(*itr);
		s.erase(*itr);
	}
	for(auto x : v) cout << x << " ";
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}