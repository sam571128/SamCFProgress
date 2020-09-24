#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int arr[100] = {};
	int n, ans = 0;
	cin >> n;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		ans += arr[__lg(tmp)];
		arr[__lg(tmp)]++;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}