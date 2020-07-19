#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s, t = "abacaba";
	cin >> s;
	if(n < 7){
		cout << "NO\n";
		return;
	}
	for(int i = 0;i <= n-7;i++){
		string tmp = s.substr(i,7);
		bool ok = 1;
		for(int j = 0;j < 7;j++){
			if(tmp[j]!='?'&&tmp[j]!=t[j]){
				ok = false;
				break;
			}
		}
		if(ok){
			string ans = s;
			
			for(int j = i;j < i+7;j++){
				ans[j] = t[j-i];
			}
			
			for(int j = 0;j < ans.size();j++){
				if(ans[j]=='?') ans[j] = 'z';
			}
			int cnt = 0;
			for(int j = 0;j <= n-7;j++){
				string check = ans.substr(j,7);
				if(check==t) cnt++;
			}
			if(cnt>1) continue;
			cout << "YES\n";
			cout << ans << "\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}