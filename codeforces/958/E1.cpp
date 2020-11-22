#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int r,b;
	cin >> r >> b;
	for(int i = 0, x, y;i < r+b;i++) cin >> x >> y;
	cout << (r==b ? "Yes\n" : "No\n"); 
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}