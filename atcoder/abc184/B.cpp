#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,x;
	cin >> n >> x;
	int now = x;
	string s;
	cin >> s;
	for(auto x : s){
		if(x == 'o') now++;
		else if(now) now--;
	}
	cout << now << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}