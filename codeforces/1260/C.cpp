#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int r,b,k;
	cin >> r >> b >> k;
	int tmp = gcd(r,b);
	r /= tmp, b /= tmp;
	if(r > b) swap(r,b);
	if((k-1)*r+1 < b) cout << "REBEL\n";
	else cout << "OBEY\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}