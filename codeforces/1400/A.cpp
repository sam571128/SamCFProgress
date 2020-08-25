#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	string s1 = "", s2 = "";
	for(int i = 0;i < n;i++) s1 += '0', s2 += '1';
	for(int i = 0;i < n;i++){
		bool ok = 1;
		for(int j = i;j < i+n;j++){
			//cout << s[0] << " " << s1[0] << (s[j]==s1[j-i])<< "\n";
			if(s[j]=='0') ok = false;
		}
		//cout << i << " " << ok << "\n";
		if(ok){
			cout << s2 << "\n";
			return;
		}
	} 
	cout << s1 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}