#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	cout << max((int)0,c-max((int)0,(c+b-a+2)/2)+1) << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}