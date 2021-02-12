#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int x,y;
	cin >> x >> y;
	int ans = 0;
	for(int i = 1;i*i <= x;i++){
		ans += max((int)0,min(x/i-i-1,y-i));
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}