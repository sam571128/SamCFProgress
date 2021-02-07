#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(i%2){
			if(s[i]=='z') s[i] = 'y';
			else s[i] = 'z';
		}else{
			if(s[i]=='a') s[i] = 'b';
			else s[i] = 'a';
		}
	}
	cout << s << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}