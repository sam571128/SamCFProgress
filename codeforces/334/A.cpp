#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a = 1, b = n*n;
	while(a < b){
		cout << a++ << " " << b-- << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}