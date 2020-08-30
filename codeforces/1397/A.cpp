#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	unordered_map<char,int> m;
	for(int i = 0;i < n;i++){
		string s;
		cin >> s;
		for(int j = 0;j < s.size();j++){
			m[s[j]]++;
		}
	}
	for(auto [a,b] : m){
		if(b%n){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}