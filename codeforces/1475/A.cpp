#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	while(n%2==0) n/=2;
	if(n>1&&n%2) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}