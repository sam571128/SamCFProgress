#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	int a = 0, b = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i]=='A') a++;
		else{
			if(a) a--;
			else b++;
		}
	}
	cout << a+b%2 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}