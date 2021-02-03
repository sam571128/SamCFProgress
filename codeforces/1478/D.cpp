#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	int gg = 0;
	for(int i = 0;i < n-1;i++){
		gg = gcd(gg,arr[i+1]-arr[i]);
	}
	if((k-arr[0])%gg) cout << "NO\n";
	else cout << "YES\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}
//