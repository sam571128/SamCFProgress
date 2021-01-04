#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	int x = 1, y = 1;
	while(a&1^1){
		x*=2, a/=2;
	}
	while(b&1^1){
		y*=2, b/=2;
	}
	if(x*y >= c){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}