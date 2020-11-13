#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


void solve(){
	set<int> s;
	int n;
	cin >> n;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		s.insert(tmp);
	}
	if(s.size()!=n) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}