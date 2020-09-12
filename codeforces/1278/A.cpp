//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s, p;
	cin >> s >> p;
	sort(s.begin(),s.end());
	int n = s.size(), m = p.size();
	for(int i = 0;i <= m-n;i++){
		string str = p.substr(i,n);
		sort(str.begin(),str.end());
		if(str==s){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}