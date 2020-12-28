#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	if(n%2||s.back()=='('){
		cout << "NO\n";
		return;
	}
	int tmp = 0;
	for(int i = 0;i < n;i++){
		if(s[i]=='('){
			tmp++;
		}else if(s[i]=='?'){
			tmp++;
		}else if(s[i]==')'){
			if(tmp){
				cout << "YES\n";
				return;
			}else{
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}