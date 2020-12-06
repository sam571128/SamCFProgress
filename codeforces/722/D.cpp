#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	set<int> s;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		s.insert(tmp);
	}
	while(true){
		int val = *s.rbegin(); s.erase(val);
		int tmp = val/2;
		while(tmp){
			if(s.find(tmp)==s.end()){
				s.insert(tmp);
				break;
			}
			tmp/=2;
		}
		if(tmp==0){
			s.insert(val);
			break;
		}
	}
	for(auto x : s) cout << x << " ";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}