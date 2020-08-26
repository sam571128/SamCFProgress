#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int mi = *min_element(arr,arr+n);
	for(auto x : arr) if(x%mi){
		cout << -1 << "\n";
		return;
	}
	cout << 2*n-1 << "\n";
	cout << arr[0] << " ";
	for(int i = 1;i < n;i++){
		cout << mi << " " << arr[i] << " ";
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}