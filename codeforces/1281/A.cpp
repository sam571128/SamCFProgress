//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	if(s.size()>=2){
		if(s.substr(s.size()-2,2)=="po"){
			cout << "FILIPINO\n";
			return; 
		}
	}
	if(s.size()>=4){
		if(s.substr(s.size()-4,4)=="desu"||s.substr(s.size()-4,4)=="masu"){
			cout << "JAPANESE\n";
			return;
		}
	}
	if(s.size()>=5){
		if(s.substr(s.size()-5,5)=="mnida"){
			cout << "KOREAN\n";
			return; 
		}

	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}