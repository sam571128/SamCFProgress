#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	cout << 3 << "\n";
	cout << "R " << n-1 << "\n";
	cout << "L " << n << "\n";
	cout << "L " << 2 << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}