#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int x;
	cin >> x;
	int ans = 0;
	for(int i = 1;;i = 2*i+1){
		//cout << x << " " << i*(i+1)/2 << "\n";
		if(x<i*(i+1)/2) break;
		ans++;
		x-=i*(i+1)/2;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}