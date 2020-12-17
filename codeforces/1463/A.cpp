#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	if((a+b+c)%9){
		cout << "NO\n";
		return;
	}
	if((a+b+c)/9 > min({a,b,c})){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}