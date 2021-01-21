#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string tmp;
	string ans;
	for(int i = 0;i < n;i++){
		if(s[i]=='0'){
			if(i==0||(i!=0&&tmp[i-1]!='1')) tmp += '1', ans += '1';
			else tmp += '0', ans += '0';
		}else if(s[i]=='1'){
			if(i==0||(i!=0&&tmp[i-1]!='2')) tmp += '2', ans += '1';
			else tmp += '1', ans += '0';
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}