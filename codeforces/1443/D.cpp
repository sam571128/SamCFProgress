#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int dec = 0;
	for(int i = n-2;~i;i--){
		if(arr[i] < dec){
			cout << "NO\n";
			return;
		}
		if(arr[i] < arr[i+1]) continue;
		dec += arr[i]-arr[i+1];
	}
	cout << "YES\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}