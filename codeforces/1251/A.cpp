#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	char now = '1';
	int cnt = 0;
	set<char> v;
	for(auto c : s){
		if(c!=now){			
			if(cnt%2&&now>='a'&&now<='z'){
				v.insert(now);
			}
			cnt = 1;
			now = c;
		}else{
			cnt++;
		}
	}
	if(cnt%2&&now>='a'&&now<='z'){
		v.insert(now);
	}
	for(auto c : v) cout << c;
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}	