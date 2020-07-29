#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int l,r;
	cin >> l >> r;
	if(r>=l*2) cout << l << " " << l*2 << "\n";
	else cout << -1 << " " << -1 << '\n';
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}