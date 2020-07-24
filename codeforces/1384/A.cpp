#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	string s = "";
	for(int i = 0;i < 55;i++) s+='a';
	cout << s << "\n";
	for(int i = 0;i < n;i++){
		s[a[i]] += 1;
		if(s[a[i]]-'a'>25) s[a[i]] = 'a';
		cout << s << "\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}