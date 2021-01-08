#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	for(int i = 0;i < min((int)2,n);i++){
		cout << 9-i%10;
	}
	for(int i = 0;i < n-2;i++){
		cout << (i+9)%10;
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}