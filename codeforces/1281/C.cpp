//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

void solve(){
	int x;
	string s;
	cin >> x >> s;
	int n = s.size();
	for(int i = 1;i <= x;i++){
		int cnt = (s[i-1]-'1');
		if(s.size() < x){
			string str = s.substr(i);
			for(int j = 0;j < cnt;j++) s += str;
		}
		n = (n + (n-i)*cnt%MOD+MOD)%MOD;
	}	
	cout << n << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}