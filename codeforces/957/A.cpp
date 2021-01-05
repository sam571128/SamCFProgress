#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	string s;
	cin >> n >> s;
	bool ok = true; int cnt = 0;
	cnt += (s[0]=='?') + (s[n-1]=='?');
	for(int i = 1;i < n;i++){
		if(s[i]!='?'&&s[i]==s[i-1]) ok = false;
		if(i<n&&s[i]=='?'&&s[i+1]==s[i-1]) cnt++;
		if(s[i]=='?'&&s[i]==s[i-1]) cnt++;
	}
	if(ok&&cnt) cout << "YES\n";
	else cout << "NO\n";
}