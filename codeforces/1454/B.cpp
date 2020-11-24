#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
void solve(){
	int n;
	cin >> n;
	set<pair<int,int>> s;
	int m[N] = {};
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(!m[tmp]) s.insert({tmp,i+1}), m[tmp] = i+1;
		else s.erase({tmp,m[tmp]});
	}
	if(s.empty()) cout << -1 << "\n";
	else cout << (*s.begin()).second << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}