#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	//Unsolved
	int a,b,x,y;
	cin >> a >> b >> x >> y;
	x++,y++;
	cout << max({(a-x)*b,(x-1)*b,(b-y)*a,(y-1)*a}) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}