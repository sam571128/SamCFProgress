#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	map<int,int> m;
	int n;
	cin >> n;
	string s;
	cin >> s;
	m[0]++;
	int tmp = 0, ans = 0;
	for(int i = 0;i < n;i++){
		tmp += (s[i]-'0')-1;
		ans += m[tmp];
		m[tmp]++;
	}
	cout << ans << "\n";
}


signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}