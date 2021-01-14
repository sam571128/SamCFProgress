#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int arr[n];
	for(auto &x : arr) cin >> x;
	bool ok = true;
	for(auto x : arr) if(x > m) ok = false;
	if(ok){
		cout << "YES\n";
		return;
	}
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			if(arr[i]+arr[j] <= m){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}