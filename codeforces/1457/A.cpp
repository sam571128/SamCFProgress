#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << max({a-c+b-d,c-1+b-d,d-1+a-c,c-1+d-1}) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}