#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int x,y;
	cin >> x >> y;
	if(abs(x-y)<=1) cout << x+y << "\n";
	else{
		cout << x + y + abs(x-y)-1 << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}