#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int pref[n] = {};
	int mx;
	int sum = pref[0] = mx = arr[0];
	for(int i = 1;i < n;i++){
		sum += arr[i];
		pref[i] = max(mx,sum);
		mx = max(pref[i],mx);
	}
	while(m--){
		int x;
		cin >> x;
		if(x > pref[n-1]&&sum <= 0){
			cout << -1 << " ";
			continue;
		}
		int ans = 0;
		if(x > pref[n-1]) ans += (x-pref[n-1]+sum-1)/sum*n, x-=(x-pref[n-1]+sum-1)/sum*sum;
		ans += lower_bound(pref,pref+n,x) - pref;
		cout << ans << " ";
	}
	cout << '\n';
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}