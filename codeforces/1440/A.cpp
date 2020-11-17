#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	string s;
	cin >> s;
	int cntz = 0, cnto = 0;
	for(auto x : s){
		if(x=='1') cnto++;
		else cntz++;
	}
	if(a > b && c < a - b) cout << b*n+c*cntz << "\n";
	else if(b > a && c < b - a) cout << a*n+c*cnto << "\n";
	else cout << a*cntz+b*cnto << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}