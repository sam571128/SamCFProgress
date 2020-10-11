#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	string s1, s2;
	int n = s.size();
	for(int i = 0;i < n;i++) if((s[i]-'a')%2) s1 += s[i]; else s2 += s[i];
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	s = s1+s2;
	bool ok = true;
	for(int i = 1;i < n;i++){
		if(abs(s[i]-s[i-1])==1) ok = false;
	}
	if(ok){
		cout << s << "\n";
		return;
	}
	ok = true;
	s = s2+s1;
	for(int i = 1;i < n;i++){
		if(abs(s[i]-s[i-1])==1) ok = false;
	}
	if(ok){
		cout << s << "\n";
	}else{
		cout << "No answer\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}