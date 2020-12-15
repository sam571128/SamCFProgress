#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	bool ok = false;
	for(int i = 0;i <= 4;i++){
		string tmp = "";
		tmp += s.substr(0,i);
		tmp += s.substr(s.size()-(4-i),4-i);
		if(tmp=="2020") ok = true;
	}
	cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}