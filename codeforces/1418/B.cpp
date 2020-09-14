#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n], b[n];
	for(auto &x : arr) cin >> x;
	for(auto &x : b) cin >> x;
	vector<int> v;
	for(int i = 0;i < n;i++){
		if(!b[i]) v.push_back(arr[i]);
	}
	sort(v.begin(),v.end());
	for(int i = 0;i < n;i++){
		if(!b[i]) arr[i] = v.back(), v.pop_back();
	}
	for(auto x : arr) cout << x << " ";
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}