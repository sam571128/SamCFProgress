#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n], pref[n+1] = {}, ma[n+1] = {};
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		pref[i+1] = pref[i] + arr[i];
		ma[i+1] = max(ma[i],pref[i+1]);
	}
	int now = 0, ans = 0;
	for(int i = 1;i <= n;i++){
		ans = max(ans,now+ma[i]);
		now += pref[i];
	}
	cout << ans << "\n";
}