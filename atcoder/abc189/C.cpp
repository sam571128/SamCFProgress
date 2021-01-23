#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int ans = 0;
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	for(int i = 0;i < n;i++){
		int mi = INT_MAX;
		for(int j = i;j < n;j++){
			mi = min(mi, arr[j]);
			ans = max(ans,mi*(j-i+1));
		}
	}
	cout << ans << "\n";
}