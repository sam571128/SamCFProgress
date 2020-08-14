#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	vector<int> v;
	int cnt = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i]=='1') cnt++;
		else if(s[i]=='0'&&cnt>0) v.push_back(cnt), cnt = 0;
	}
	if(cnt) v.push_back(cnt);
	sort(v.begin(),v.end(),greater<int>());
	int ans = 0;
	for(int i = 0;i < v.size();i+=2){
		ans += v[i];
	}
	cout << ans << "\n";
}


signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}