#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int mx = 0, ans = 1;
	for(int i = 2;i <= 1000;i++){
		int cnt = 0;
		for(auto x : arr) if(x%i==0) cnt++;
		if(cnt > mx) ans = i, mx = cnt;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}