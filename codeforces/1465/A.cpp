#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	reverse(s.begin(),s.end());
	int cnt = 0;
	for(auto c : s){
		if(c==')'){
			cnt++;
		}else{
			break;
		}
	}
	if(cnt > n-cnt){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}