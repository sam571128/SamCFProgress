#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c,r;
	cin >> a >> b >> c >> r;
	if(a > b) swap(a,b);
	if(b<=c-r||a>=c+r){
		cout << b-a << "\n";
		return;
	}
	if(a <= c-r && b >= c+r){
		cout << b-a-2*r << "\n";
		return;
	}
	if(a <= c-r && b < c+r){
		cout << c-r-a << "\n";
		return;
	}
	if(a >= c-r && b >= r+c){
		cout << b-(r+c) << "\n";
		return;
	}
	if(a <= c-r && b >= r+c){
		cout << c-r-a << "\n";
		return;
	}
	cout << 0 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}