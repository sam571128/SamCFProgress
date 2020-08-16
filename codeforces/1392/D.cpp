#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v;
	char tmp = s[0];
	int cnt = 1;
	for(int i = 1;i < n;i++){
		if(s[i]!=tmp){
			v.push_back(cnt);
			tmp = s[i];
			cnt = 1;
		}else{
			cnt++;
		}
		if(i==n-1){
			if(s[i]==s[0]){if(!v.empty())v[0]+=cnt;}
			else{v.push_back(cnt);}
		}
	}
	if(v.empty()) v.push_back(cnt);
	int ans = 0;
	for(int i = 0;i < v.size();i++){
		//cout << v[i] << " ";
		if(v.size()!=1)ans += v[i]/3;
		else ans += (v[i]+2)/3;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}