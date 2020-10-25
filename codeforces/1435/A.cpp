#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	for(int i = 0;i < n;i+=2){
		cout << -arr[i+1] << " " << arr[i] << " ";
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}