#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	map<int,int> m;
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}
	string s = "First";
	if(n%2==0){
		bool ok = true;
		for(auto [a,b] : m){
			if(b&1) ok = false;
		}
		if(ok) cout << "Second\n";
		else cout << "First\n";
	}else{
		cout << "Second\n";
		return;
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}