#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << min(abs(c-d)+b,a-1) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}