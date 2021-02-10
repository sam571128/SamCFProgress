#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	if(a>=b){
		cout << "YES\n";
		return;
	}
	if(a>=4){
		cout << "YES\n";
		return;
	}
	while(b > 4){
		b = (b+2)/3*2;
	}
	if(a==2&&b==3){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}