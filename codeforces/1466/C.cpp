#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	string tmp = s;
	int cnt = 0;
	int n = s.size();
	for(int i = 1;i < n;i++){
		if((i>=2&&s[i]==s[i-2])||s[i]==s[i-1])
			s[i] = char('a'+(s[i]-'a'+1)%26);
		while(s[i]!=tmp[i]&&((i>=2&&s[i]==s[i-2])||s[i]==s[i-1]||(i<n-1&&s[i]==s[i+1])||(i<n-2&&s[i]==s[i+2]))){
			s[i] = char('a'+(s[i]-'a'+1)%26);
		}
	}
	//cout << s << "\n";
	for(int i = 0;i < n;i++){
		if(s[i]!=tmp[i]) cnt++;
	}
	cout << cnt << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}