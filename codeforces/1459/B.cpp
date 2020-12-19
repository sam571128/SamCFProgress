#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	if(n <= 2) cout << 4 << "\n";
	else{
		if(n%2==0) cout << (n/2+1)*(n/2+1) << "\n";
		else cout << (n/2+1)*(n/2+1+n/2+3) << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}