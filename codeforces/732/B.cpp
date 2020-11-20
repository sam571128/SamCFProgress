#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(arr[i] + arr[i+1] < k) ans += k-arr[i]-arr[i+1], arr[i+1] = k-arr[i];
	}
	cout << ans << "\n";
	for(auto &x : arr) cout << x << " ";
}
