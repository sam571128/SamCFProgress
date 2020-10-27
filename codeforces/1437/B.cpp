#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int num1 = 0, num2 = 0;
	for(int i = 1;i < s.size();i++){
		if(s[i]=='1'&&s[i]==s[i-1]) num1++;
		if(s[i]=='0'&&s[i]==s[i-1]) num2++;
	}
	cout << max(num1,num2) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}