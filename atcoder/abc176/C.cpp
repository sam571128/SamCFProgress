#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	int mx = -1, ans = 0;
	for(auto x : a){
		mx = max(mx, x);
		ans += mx-x;
	}
	cout << ans << "\n";
}