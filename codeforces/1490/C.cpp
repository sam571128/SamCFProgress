#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

set<int> s;
void init(){
	for(int i = 1;i <= 1e4;i++){
		s.insert(i*i*i);
	}
}

void solve(){
	int x;
	cin >> x;
	for(auto y : s){
		if(y >= x) break;
		if(s.find(x-y)!=s.end()){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

signed main(){
	fastio
	init();
	int t = 1;
	cin >> t;
	while(t--) solve();
}