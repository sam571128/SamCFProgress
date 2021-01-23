#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int arr[n+1] = {}, pref[n+2] = {};
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
		pref[i] = pref[i-1]+(i&1) * (arr[i]-arr[i-1]);
	}
	pref[n+1] = pref[n] + ((n+1)&1) * (m-arr[n]);
	int ans = pref[n+1];
	for(int i = 1;i <= n;i++){
		ans = max(ans, pref[i]+m-arr[i]-(pref[n+1]-pref[i])-1);
	}
	cout << ans << "\n";
}