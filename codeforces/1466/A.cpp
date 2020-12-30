#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	set<int> s;
	int arr[n];
	for(auto &x : arr) cin >> x;
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			s.insert(arr[j]-arr[i]);
		}
	}
	cout << s.size() << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}